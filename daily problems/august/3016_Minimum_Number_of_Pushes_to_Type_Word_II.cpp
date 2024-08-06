class Solution {
public:
    int minimumPushes(string word) {
        vector<int> vect(26,0);

        for(auto w : word){
            vect[w-'a']++;
        }

        sort(vect.begin(),vect.end(),[](int a,int b){
            return a > b;
        });

        int sum = 0;
        int count = 0;
        for(auto it : vect){
            if(count<8) sum+=it;
            else if(count<16) sum+=it*2;
            else if(count<24) sum+=it*3;
            else sum+=it*4;
            count++;
        }
        return sum;
    }
};