class BIT {
	private:
		static const long long int MAX = 100005;
		long long int tree_arr[MAX];

		long long int step(long long int index) {
			return ((index ^ (index + 1)) >> 1) + 1;
		}
	public:
		BIT(){
			for(long long int i = 0; i < MAX; i++){
				tree_arr[i] = 0;
			}
		}
		
		void pointUpdata(long long int index, long long int delta) {
			while(index < MAX) {
				/* do something */
				tree_arr[index] += delta;
				/* index += step(index) */
				index += step(index);
			}
		}
		
		void debug(){
			for(long long int i = 0; i < MAX; i++){
				printf("%lld ", tree_arr[i]);
			}
			printf("\n");			
		}

		long long int pointQuery(long long int index) {
			if(index < 0 || index >= MAX){
				return 0;
			}
			long long int sum = 0;
			while(index >= 0) {
				/* do something */
				sum += tree_arr[index];
				/* index += step(index) */
				index -= step(index);
			}
			return sum;
		}
};
