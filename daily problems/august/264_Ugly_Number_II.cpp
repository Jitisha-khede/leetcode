class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> st;
        int i=0;
        long c=1;
        st.insert(1);

        while(i<n){

            c = *st.begin();
            st.erase(st.begin());
            st.insert(c*2);
            st.insert(c*3);
            st.insert(c*5);

            i++;
        }

        return c;
    }
};