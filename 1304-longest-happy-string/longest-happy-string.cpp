class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        int x= 0,y = 0,z = 0;
        int n = a+b+c;
        for(int i =0;i<n;i++){
            if((a>=b && a>=c && x!=2) || (y==2 && a>0) || (z==2 && a>0)){
                ans.push_back('a');
                a--;
                x++;
                y = 0;
                z = 0;
            }
            else if((b>=a && b>=c && y!=2) || (x==2 && b>0) || (z==2 && b>0)){
                ans.push_back('b');
                b--;
                y++;
                x = 0;
                z = 0;
            }
            else if((c>=b && c>=a && z!=2) || (y==2 && c>0) || (x==2 && c>0)){
                ans.push_back('c');
                c--;
                z++;
                x = 0;
                y = 0;
            }
        }
        return ans;
    }
};