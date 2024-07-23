class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="/" && tokens[i]!="*"){
                
                int num = stoi(tokens[i]);
                st.push(num);    
                                
            }
            else{
                int elem1 = st.top();
                st.pop();
                int elem2 = st.top();
                st.pop();
                if(tokens[i]=="+") st.push(elem1+elem2);
                else if(tokens[i]=="-") st.push(elem2-elem1);
                else if(tokens[i]=="*") st.push(elem1*elem2);
                else if(tokens[i]=="/") st.push(elem2/elem1);
            }
        }
        return st.top();
    }
};