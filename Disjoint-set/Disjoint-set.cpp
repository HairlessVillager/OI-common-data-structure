class DisjointSet{
	private:
		static const int MAX = 50000;
		int set[MAX];
	public:
		DisjointSet(){
			for(int i = 0; i < MAX; i++){
				set[i] = i;
			}
		}
		
		int findRoot(int index){
			if(set[index] == index){
				return index;
			}
			else{
				return set[index] = findRoot(set[index]);
			}
		}
		
		bool isSameRoot(int index1, int index2){
			return findRoot(index1) == findRoot(index2);
		}
		
		void merge(int index1, int index2){
			set[findRoot(index1)] = findRoot(index2);
		}
};
