class Solution {
    public:
        vector<vector<int>> generate(int numRow) {
            vector<vector<int>> ret;
            vector<int> temp;
            if(numRow>=1){
                temp.push_back(1);
                ret.push_back(temp);
                numRow--;
                if(numRow==0) return ret;
            }
            if(numRow>=2){
                temp.push_back(1);
                ret.push_back(temp);
                numRow--;
                if(numRow==0) return ret;
            }
            while(numRow>0){
                vector<int> v;
                v.push_back(1);
                for(int i=0;i<temp.size()-1;i++){
                    v.push_back(temp[i]+temp[i+1]);
                }
                v.push_back(1);
                temp=v;
                ret.push_back(temp);
                numRow--;
            }
            return ret;
        }
    };