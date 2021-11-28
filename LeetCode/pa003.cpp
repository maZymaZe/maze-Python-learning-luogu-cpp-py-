#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> PII;

int _pointId = 0;
map<PII, int> pointIdMap;
// 把(x,y)映射到id
int getPointId(const PII& point) {
    if (!pointIdMap.count(point)) {
        pointIdMap[point] = ++_pointId;
    }
    return pointIdMap[point];
}

long pDist[300000]
          [4];  // pDist[id][dir] 到达点id的dir方向最短距离(时间) 设-1为最大值
struct Node {
    int x, y, pointId, dir;
    long dist;
    Node(int _x, int _y, int _pointId, int _dir, long _dist)
        : x(_x), y(_y), pointId(_pointId), dir(_dir), dist(_dist) {}
    Node() {}
    bool operator<(const Node& rhs) const {
        // 设 -1 为最大值
        // 将小于运算符设置为大于运算 这样优先队列默认就是小顶堆了~
        if (dist == -1)
            return true;
        if (rhs.dist == -1)
            return false;
        return dist > rhs.dist;
    }
};

// 存图
vector<vector<int>> G[300000];
// visited[id][dir] 判断一个点的某个方向是否已经访问到
// dir: 0up 1right 2down 3left
int visited[300000][4];

// 获取两条垂直直线的交点
void getIntersection(vector<PII>& intersection,
                     vector<int>& h,
                     vector<int>& v) {
    if (h[0] <= v[0] && v[0] <= h[2] && v[1] <= h[1] && h[1] <= v[3]) {
        intersection.emplace_back(v[0], h[1]);
    }
}

int n, sx, sy, tx, ty;
long t1, t2, t3;
vector<vector<int>> hor,
    ver;  // 分别存水平和垂直的边 每个边存(x1,y1,x2,y2)四个点

void solveEdge(vector<int>& edge, bool isHorizontal) {
    vector<PII> intersection;  // 存该边的交点
    if (isHorizontal) {
        for (vector<int>& v :
             ver) {  // 遍历垂直边 收集该水平边和所有垂直边的交点
            getIntersection(intersection, edge, v);
        }
    } else {
        for (vector<int>& h : hor) {
            getIntersection(intersection, h, edge);
        }
    }
    // 端点也加进去 以处理两条平行的边有交点的情况
    // （但是经测试标板好像没有处理这种情况
    intersection.emplace_back(edge[0], edge[1]);
    intersection.emplace_back(edge[2], edge[3]);
    // 如果起始点和终点在该边上也加进去
    if (isHorizontal) {
        if (edge[1] == sy && edge[0] < sx && edge[2] > sx) {
            intersection.emplace_back(sx, sy);
        }
        if (edge[1] == ty && edge[0] < tx && edge[2] > tx) {
            intersection.emplace_back(tx, ty);
        }
    } else {
        if (edge[0] == sx && edge[1] < sy && edge[3] > sy) {
            intersection.emplace_back(sx, sy);
        }
        if (edge[0] == tx && edge[1] < ty && edge[3] > ty) {
            intersection.emplace_back(tx, ty);
        }
    }
    // 排序 去掉重复值
    sort(intersection.begin(), intersection.end());
    intersection.resize(unique(intersection.begin(), intersection.end()) -
                        intersection.begin());
    // 把相邻的两个交点建边
    for (int i = 0; i < intersection.size() - 1; i++) {
        int id1 = getPointId(intersection[i]);
        int id2 = getPointId(intersection[i + 1]);
        // 建图
        G[id1].push_back(
            {intersection[i + 1].first, intersection[i + 1].second, id2});
        G[id2].push_back({intersection[i].first, intersection[i].second, id1});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(pDist, -1, sizeof pDist);

    cin >> n;
    int x1, y1, x2, y2;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            if (y1 > y2)
                swap(y1, y2);  // 保证左下的点在前 右上的点在后 方便后面判断交点
            ver.push_back({x1, y1, x2, y2});
        } else {
            if (x1 > x2)
                swap(x1, x2);
            hor.push_back({x1, y1, x2, y2});
        }
    }

    cin >> sx >> sy >> tx >> ty;
    cin >> t1 >> t2 >> t3;

    for (vector<int>& h : hor) {  // 处理水平边
        solveEdge(h, true);
    }
    for (vector<int>& v : ver) {  // 处理垂直边
        solveEdge(v, false);
    }

    priority_queue<Node> q;
    for (int i = 0; i < 4; i++) {  // 起点四个方向都加进去
        int pointId = getPointId({sx, sy});
        pDist[pointId][i] = 0;
        q.emplace(sx, sy, pointId, i, 0);
    }

    // dijkstra 求最短路
    while (q.size()) {  // 每次找距离最小的
        Node u = q.top();
        q.pop();
        long dist = pDist[u.pointId][u.dir];
        // 终点
        if (u.x == tx && u.y == ty) {
            cout << dist;
            break;
        }
        if (visited[u.pointId][u.dir]) {
            continue;
        }
        visited[u.pointId][u.dir] = 1;
        for (int i = 0; i < G[u.pointId].size(); i++) {
            vector<int> v = G[u.pointId][i];
            int x = v[0], y = v[1], id = v[2], dir;
            // 判断方向
            if (x < u.x)
                dir = 3;  // left
            if (x > u.x)
                dir = 1;  // right
            if (y < u.y)
                dir = 2;  // down
            if (y > u.y)
                dir = 0;  // up

            if (!visited[id][dir] &&
                (u.dir + 2) % 4 != dir) {  // 未访问过且方向不能是反向
                long d = abs(u.x - x) + abs(u.y - y);  // 两点之间的曼哈顿距离
                long t = 0;          // 红路灯等待的时间
                if (dir == u.dir) {  // 直行
                    t = max(t1 - dist % (t1 + t2 + t3), 0L);
                } else if ((dir + 1) % 4 == u.dir) {  // 左转
                    long c = dist % (t1 + t2 + t3);
                    if (c < t1) {
                        t = t1 - c;
                    } else if (c >= t1 + t2) {
                        t = t1 + t2 + t3 - c + t1;
                    }
                }  // 右转不用等灯
                if (pDist[id][dir] == -1 || pDist[id][dir] > dist + d + t) {
                    pDist[id][dir] = dist + d + t;
                    q.emplace(x, y, id, dir, dist + d + t);
                }
            }
        }
    }

    return 0;
}
