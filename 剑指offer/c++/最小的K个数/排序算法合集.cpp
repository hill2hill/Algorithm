/*
题目描述
输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

/*应当是排序的思路，先排序，然后从左到右找；

或者直接找出第k大的数，然后返回那些未经排序的就可以


*/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    	vector<int> result, sorted;
        if(input.size() == 0 || k <= 0 || k > input.size())	return result;//k不能太大也不能太小，vector不能为空
        sorted = sort(input);
        for(int i = 0; i < k; i++){
        	result.push_back(sorted[i]);
        }
        return result;
    }
    
    vector<int> sort(vector<int> input){
    	/*
    	input非空
    	*/
    	return InsertSort(input);
    	//选择	排序
    	//冒泡	排序
    	//插入	排序:	InsertSort(input)
    	//希尔	排序
    	//归并	排序
    	//快速	排序
    	//堆		排序
    	//基数	排序
    	//桶		排序
    	//计数	排序
        
        
    }

    vector<int> InsertSort(vector<int> input){
    	/*
		插入排序
		输入：非空vector<int>  	input;
		输出：排序后的新vector	sorted;

		思路：	先拿来input的第0个元素，作为sorted的第一个元素；
					查看input的第1个元素，“搜索”其在sorted应在的位置 ——> 插入该位置；
					查看input的第2个元素，“搜索”其在sorted应在的位置 ——> 插入该位置；
					... ...
					查看input的最后一个元素，“搜索”其在sorted应在的位置 ——> 插入该位置；
				返回sorted；


				“搜索”：	查看sorted的第0空位是否适合？如果适合直接中断改循环，否则继续。
						查看sorted的第1空位是否适合？如果适合直接中断改循环，否则继续。
						... ...
						查看sorted的最后空位是否适合？（若执行到此步，则一定适合）

		分析：	上述思路默认按照升序排列进行。

				如果输入的input是降序排列，那每一次都会直接插入在sorted的最前面；
				时间复杂度为O(N)
				如果输入的input已经是升序排列，那么每次都要遍历到sorted的最后进行插入；
					（判断是否大于sort当前最大元素是可以的，但是如果是倒数第二位呢？不可能直接就知道某个序列的排列）
				时间复杂度为O(N^2)

				空间复杂度：O(1)
				
							PS：我实现的这个版本是值传递，不是引用传递，所以空间复杂度是O(N),不够精炼
    	*/
		vector<int> sorted;
		sorted.push_back(input[0]);
		int index =  1;
		while(sorted.size() < input.size()){
			//cout<<"sorted.size():" << sorted.size()<<endl;
			for(int i = 0; i < sorted.size(); i++){
				//cout <<"\t i:" <<i<<endl;
				if(input[index] < sorted[0]){//在头部插入
					sorted.insert(sorted.begin(),input[index]);
					break;
				}
				else if(input[index] > sorted[sorted.size()-1]){//在尾部插入
					sorted.push_back(input[index]);
					break;
				}
				else if(input[index] <= sorted[i] && input[index] >= sorted[i-1]){//在中间插入
					sorted.insert(sorted.begin()+i,input[index]);
					break;
				}
			}
			index++;
		}
		return sorted;
	}
};