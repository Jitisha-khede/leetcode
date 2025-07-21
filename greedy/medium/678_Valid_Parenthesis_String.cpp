class Solution {
public:
    // bool check(int c,int ind, string s){
    //     if(c<0) return false;
    //     if(ind>=s.size()){
    //         if(c==0) return true;
    //         return false;
    //     }
    //     if(s[ind]=='('){
    //         return check(c+1,ind+1,s);
    //     }
    //     else if(s[ind]==')') {
    //         return check(c-1,ind+1,s);
    //     }
    //     else{
    //         return check(c,ind+1,s) || check(c+1,ind+1,s) || check(c-1,ind+1,s);
    //     }
    // }

    bool checkValidString(string s) {
        //BRUTE FORCE
        // return check(0,0,s);

        //OPTIMAL
        int mini = 0, maxi = 0;

        if(s[0]==')') return false;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                mini++;
                maxi++;
            }
            else if(s[i]==')'){
                mini--;
                maxi--;
            }
            else{
                mini--;
                maxi++;
            }
            if(maxi<0) return false;
            if(mini<0) mini = 0;
        }
        if(mini==0)return true;
        return false;
    }
};