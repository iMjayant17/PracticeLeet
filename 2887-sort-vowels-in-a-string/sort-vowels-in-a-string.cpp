class Solution {
public:
    string sortVowels(string arr) {
        vector<char>cap;
        vector<char> sml;
        for(int i = 0;i<arr.length();i++){
            if(arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i]=='o' || arr[i]=='u' ){
                sml.push_back(arr[i]);
            }
            if(arr[i]=='A' || arr[i]=='E' || arr[i]=='I' || arr[i]=='O' || arr[i]=='U'){
                cap.push_back(arr[i]);
            }
        }
        sort(cap.begin(),cap.end());
        sort(sml.begin(),sml.end());
//         for(auto i:s){
//             cout<<i<<" ";
//         }
        
//         cout<<endl;
        
        for(auto i:sml){
            cap.push_back(i);
        }
        int j = 0;
      for(int i = 0;i<arr.length();i++){
            if(arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i]=='o' || arr[i]=='u' || arr[i]=='A' || arr[i]=='E' || arr[i]=='I' || arr[i]=='O' || arr[i]=='U'){
                arr[i] = cap[j];
                j++;
            }
        }
          cout<<(char)65<<endl;  // typecasting
        
        return arr;
    }
};