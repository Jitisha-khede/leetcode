class Solution {
public:
    int minimumCost(int m, int n, vector<int>& H, vector<int>& V) {
        sort(H.begin(),H.end());
        sort(V.begin(),V.end());

        int vpiece = 1, hpiece = 1;
        int sum = 0;

        while(!H.empty() &&  !V.empty()){
            if(H.back()>V.back()){
                sum+=H.back()*hpiece;
                vpiece++;
                H.pop_back();
            }
            else{
                sum+=V.back()*vpiece;
                hpiece++;
                V.pop_back();
            }
        }
        if(!H.empty()){
            while(!H.empty()){
                sum+=H.back()*hpiece;
                H.pop_back();
            }
        }
        if(!V.empty()){
            while(!V.empty()){
                sum+=V.back()*vpiece;
                V.pop_back();
            }
        }
        return sum;
    }
};