/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int,int> mp;
    int dfs(vector<Employee*> employees, int id){
        int ret=employees[mp[id]]->importance;
        for(auto i:employees[mp[id]]->subordinates){
            ret+=dfs(employees,i);
        }
        return ret;
    }
    int getImportance(vector<Employee*> employees, int id) {
        
        int l=employees.size();
        for (int i=0;i<l;i++) {
            mp[employees[i]->id] =i;
        }
        return dfs(employees,id);
    }
};