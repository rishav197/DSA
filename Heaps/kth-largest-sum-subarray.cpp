/*
approach-1: Using nested for loop and sorting 
*/
#include<algorithm>

int getKthLargest(vector<int> &arr, int k)
{
	vector<int> sumStore;

	int n = arr.size();

	for(int i=0; i<n; i++){
		int sum = 0;

		for(int j=i; j<n; j++){
			sum+=arr[j];
			sumStore.push_back(sum);
		}
	}

	sort(sumStore.begin(), sumStore.end());

	return sumStore[sumStore.size() - k];
}


/*approach 2: using Min Heap
*/
#include<queue>

int getKthLargest(vector<int> &arr, int k)
{

	int n = arr.size();
	
	priority_queue<int, vector<int>, greater<int>> minhp;

	for(int i=0; i<n; i++){
		int sum = 0;
		for(int j=i; j<n; j++){
			sum += arr[j];
			if(minhp.size()<k){
				minhp.push(sum);
			}
			else{
				if(sum>minhp.top()){
					minhp.pop();
					minhp.push(sum);
				}
			}
		}
	}


	return minhp.top();
}