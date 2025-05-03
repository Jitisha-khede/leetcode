class Solution {
    public:
        string pushDominoes(string d) {
            int n = d.size();
            vector<int> r(n),l(n),res(n);
    
            for(int i=0;i<n;i++){
                if(d[i]=='R') r[i]=i;
                else if(d[i]=='.'){
                    if(i>0){
                        r[i] = r[i-1];
                    }
                    else{
                        r[i]=-1;
                    }
                }
                else r[i]=-1; 
            }   
    
            for(int i=n-1;i>=0;i--){
                if(d[i]=='L') l[i]=i;
                else if(d[i]=='.') {
                    if(i<n-1){
                        l[i]=l[i+1];
                    }
                    else{
                        l[i] = -1;
                    }
                }
                else l[i]=-1;
            }
    
            string s(n,' ');
            for(int i=0;i<n;i++){
               int distL = abs(i-l[i]);
               int distR = abs(i-r[i]);
    
               if(l[i]==r[i]) s[i]='.';
               else if(l[i] == -1) s[i]='R';
               else if(r[i] == -1) s[i]='L';
               else if(distL==distR) s[i]='.';
               else{
                s[i] = distL<distR ? 'L':'R';
               }
            }
            return s;
        }
    };