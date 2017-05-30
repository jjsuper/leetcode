class Solution {
public:
    int myAtoi(string str) {
        size_t index = str.find_first_not_of(' ');
        if(index == str.npos) return 0;
        long result = 0;
        bool negative = false;
        if(str[index] == '-') {
            negative = true;
            index++;
        } else if(str[index] == '+') {
            index++;
        }
        for(int i=index; i<str.size(); i++) {
            if(isdigit(str[i])) {
                result = result * 10 + (str[i]-'0');
                if(negative && -result <= INT_MIN) return INT_MIN;
                if(!negative && result >= INT_MAX) return INT_MAX;
            } else {
                break;
            }
        }
        if(negative) result = -result;

        return int(result);
    }
};