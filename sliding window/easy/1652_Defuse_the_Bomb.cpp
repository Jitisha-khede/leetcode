class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int sum = 0;
        int n=code.size();
        int j=0;
        code.insert(code.end(),code.begin(),code.end());
        vector<int> vect(n,0);
        if(k==0){
            return vect;
        }
        
            
            if(k>0){
                for(int i=0;i<2*n-1;i++){
                    sum+=code[i];
                    if(i>=k && j<n){
                        sum-=code[i-k];
                        vect[i-k]=sum;
                        j++;
                    }     
                }
            }
            if(k<0){
                for(int i = 0;i<2*n-1;i++){
                    sum+=code[i%n];
                    if(i>=-k-1 && j<n){
                        vect[(i+1)%n]=sum;
                        sum-=code[i+k+1];
                        j++;
                    }
                }
            }
        
        return vect;
    }
};