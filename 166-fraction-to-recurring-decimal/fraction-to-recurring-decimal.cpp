class Solution {
public:
    string fractionToDecimal(int long numerator, int long denominator) {
        long before_point=0;
        bool positive=true;
        
        if((numerator>0 && denominator<0)||(numerator<0 && denominator>0) ){
            positive=false;
        }
        if(numerator==0){
            return "0";
        }

        vector<int> after_point;

        before_point=(long)abs(numerator/denominator);
        numerator=(long)abs(numerator); denominator=(long)abs(denominator);

        numerator%=denominator;  //reminder

        unordered_map<int,vector<int>> visited;
        int pos=-1;

        while(numerator!=0){
            if(visited[numerator].size()!=0){
                pos=visited[numerator][0];
                break;
            }
            visited[numerator].push_back(after_point.size());
            numerator*=10;
            after_point.push_back(numerator/denominator);
            numerator%=denominator;
        }

        string s;
        if(positive==false){
            s="-";
        }
        s=s+to_string(before_point);
        if(after_point.size()!=0){
            string after;
            s=s+".";
            if(pos!=-1){
            for(int i=0;i<pos;i++){
                s=s+to_string(after_point[i]);
            }
                s=s+"(";
                for(int i=pos;i<after_point.size();i++){
                    s=s+to_string(after_point[i]);
                }
                s=s+")";
            }
            else{
                for(int i=0;i<after_point.size();i++){
                    s=s+to_string(after_point[i]);
                }
            }

        }

        return s;

    }
};