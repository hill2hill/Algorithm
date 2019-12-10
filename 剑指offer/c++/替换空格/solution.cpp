class Solution {
public:
	void replaceSpace(char *str,int length) {
        if (length < 1 || str == nullptr) return;
        int space_n = 0;
        for(int i = 0; i < length; i++){
            if(str[i] == ' ')   space_n++;
        }
        int new_length = length + 2 * space_n;
        str[new_length] = '\0';
        for(int left = length-1, right = new_length - 1; left > -1; left--){
            if(str[left] == ' '){
                str[right--] = '0';
                str[right--] = '2';
                str[right--] = '%';
            }
            else{
                str[right--] = str[left];
            }
        }
	}
};
