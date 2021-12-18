struct node {
    int l, r;
    long long now_score, start_score;
} stats[50500];

#define prev(x) ((x) == 0 ? (n - 1) : ((x)-1))
#define next(x) ((x) == n - 1 ? 0 : ((x) + 1))

class Solution {
   public:
    long long ringGame(vector<long long>& challenge) {
        int n = challenge.size();
        int pre[50500] = {0};
        std::function<int(int, int[])> getPre = [&](auto x, auto pre) {
            return x == pre[x] ? x : pre[x] = getPre(pre[x], pre);
        };

        priority_queue<pair<long long, int>> q;
        // 设置每一段的初始范围、初始分数和合并后的总分
        for (int i = 0; i < n; i++) {
            pre[i] = i;
            stats[i].l = stats[i].r = i;
            stats[i].start_score = stats[i].now_score = challenge[i];
            q.emplace(-stats[i].start_score, i);
        }

        while (!q.empty()) {
            auto x = q.top().second;
            q.pop();

            // 当前节点不是所在集合的根节点，说明已被合并过，直接跳过
            if (pre[x] != x)
                continue;
            // 所有线段被合并为同一个
            if (next(stats[x].r) == stats[x].l)
                break;

            int left = prev(stats[x].l), right = next(stats[x].r);
            int choice = left;
            long long compact = challenge[left];
            // 取出相邻线段中，需求分数较小的
            if (challenge[left] > challenge[right])
                choice = right, compact = challenge[right];

            // 已无法直接合并，计算是否需要提升初始分值
            if (compact > stats[x].now_score) {
                long long min_start = 0;
                // 先计算使stats[x].now_score | y大于边界值的最小的y
                // 吐槽一下力扣还不支持C++20，不然应该能写的更好看。。。。。。
                for (int i = 63; i >= 0; i--) {
                    auto xe = (stats[x].now_score >> i) & 1;
                    auto ye = (compact >> i) & 1;
                    // now_score当前二进制位为1，目标值为0，后续全是0也已经满足stats[x].now_score
                    // | y不小于边界值，故直接退出
                    if (xe && !ye)
                        break;
                    // 对应的真值表为：
                    //    xe  ye  y
                    //     0   0  0
                    //     0   1  1
                    //     1   0  0 (直接退出)
                    //     1   1  0
                    if (!xe && ye)
                        min_start += 1LL << i;
                }
                // 若计算的y比原本的初始值大，则直接用计算值
                // 否则抹去stats[x].start_score中比y的最低的1后面的1
                // 例如初始值是10011，计算的y是00100，应忽略10011最后面的两个1
                // 不难注意这里不会存在进位问题，因为start_score和计算得到的min_start不可能在相同的二进制位上均为1，这与求解的过程是相悖的
                if (stats[x].start_score >= min_start)
                    min_start += stats[x].start_score -
                                 (((min_start & (-min_start)) - 1) &
                                  stats[x].start_score);
                // 若提升后的初始值高于边界线段的初始值，则无扩展的必要，等待边界向这里扩展即可
                // 否则调整初始值，重新计算它对分数的影响
                if (min_start < stats[choice].start_score) {
                    stats[x].start_score = min_start;
                    stats[x].now_score |= min_start;
                    q.emplace(-stats[x].start_score, x);
                }
                continue;
            }

            // 可以扩展，在并查集上合并，并调整范围和总得分
            choice = getPre(choice, pre);
            pre[choice] = pre[x];
            stats[x].now_score |= stats[choice].now_score;
            if (next(stats[choice].r) == stats[x].l)
                stats[x].l = stats[choice].l;
            else
                stats[x].r = stats[choice].r;
            q.emplace(-stats[x].start_score, x);
        }

        return stats[getPre(1, pre)].start_score;
    }
};