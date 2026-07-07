class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n = groups.size();
        
        vector<int> assigned(n,-1);

        unordered_map<int,int> map;

        for(int i = 0; i<elements.size();i++){
            if(map.count(elements[i])){
                map[elements[i]] = min(map[elements[i]], i);
            }
            else{
                map[elements[i]] = i;
            }
        }

        for(int i = 0;i<n;i++){
            for(int x = 1;x*x<=groups[i];x++){
                if(groups[i] % x == 0){
                    int first = x;
                    int second = groups[i] / x;

                    if(map.count(first)){
                        if(assigned[i] == -1){
                            assigned[i] = map[first];
                        }
                        else{
                            assigned[i] = min(assigned[i] , map[first]);
                        }
                    }

                    if(map.count(second)){
                        if(assigned[i] == -1){
                            assigned[i] = map[second];
                        }
                        else{
                            assigned[i] = min(assigned[i] , map[second]);
                        }
                    }

                }
            }
        }

        return assigned;
    }
};