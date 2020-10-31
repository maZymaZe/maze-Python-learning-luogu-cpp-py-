struct pr{int a,b;};
class AnimalShelf {
public:

    queue<pr> q[2];
    int cnt=0;
    AnimalShelf() {

    }
    
    void enqueue(vector<int> animal) {
        q[animal[1]].push({animal[0],cnt++});
    }
    
    vector<int> dequeueAny() {
        if(q[0].empty()&&q[1].empty())return{-1,-1};
        if(q[0].empty()){int t=q[1].front().a;q[1].pop();return{t,1};}
        if(q[1].empty()){int t=q[0].front().a;q[0].pop();return{t,0};}
        if(q[1].front().b<q[0].front().b){int t=q[1].front().a;q[1].pop();return{t,1};}
        int t=q[0].front().a;q[0].pop();return{t,0};
    }
    
    vector<int> dequeueDog() {
        if(q[1].empty())return{-1,-1};
        int t=q[1].front().a;q[1].pop();return{t,1};
    }
    
    vector<int> dequeueCat() {
        if(q[0].empty())return{-1,-1};
        int t=q[0].front().a;q[0].pop();return{t,0};
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */