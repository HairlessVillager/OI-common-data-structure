#include <cstdio>
#include <cstring>
#include <cctype>

class Bignum {
	private:
		static const int MAX = 4000;
		int value[MAX];
	public:
		// lowest bit : i = 0
		Bignum() {
			for(int i = 0; i < MAX; i++) {
				value[i] = 0;
			}
		}

		int getMax() {
			return MAX;
		}

		int readBit(int index) {
			index %= MAX;
			return value[index];
		}

		void writeBit(int index, int v) {
			index %= MAX;
			v %= 10;
			value[index] = v;
		}

		void scan() {
			char str[MAX];
			scanf("%s", str);
			int len = strlen(str);

			for(int i = 0; i < len; i++) {
				if(isdigit(str[i])){
					value[len - i - 1] = str[i] - '0';
				}
				else{
					value[len - i - 1] = 0;
				}
			}
		}

		void print() {
			int i = MAX - 1;
			for(; value[i] == 0 && i > 0; i--);
			if(i == 0) {
				printf("%d", value[0]);
			} else {
				for(; i >= 0; i--) {
					printf("%d", value[i]);
				}
			}
		}

		int getLen() {
			int i = MAX - 1;
			for(; value[i] == 0; i--);
			return i + 1;
		}

		void operator=(const unsigned long long int& N) {
			unsigned long long int A = N;
			for(int i = 0; A > 0; i++) {
				value[i] = A % 10;
				A /= 10;
			}
		}

		Bignum operator+(const Bignum& B) {
			Bignum res;
			for(int i = 0; i < MAX; i++) {
				res.value[i] = this->value[i] + B.value[i];
			}
			for(int i = 0; i < MAX - 1; i++) {
				res.value[i+1] += res.value[i] / 10;
				res.value[i] = res.value[i] % 10;
			}
			return res;
		}

		Bignum operator*(const Bignum& B) {
			Bignum res;
			for(int i = 0; i < MAX / 2; i++) {
				for(int j = 0; j < MAX / 2; j++) {
					res.value[i+j] += this->value[i] * B.value[j];
				}
			}
			for(int i = 0; i < MAX - 1; i++) {
				res.value[i+1] += res.value[i] / 10;
				res.value[i] = res.value[i] % 10;
			}
			return res;
		}

		void operator=(const Bignum& B) {
			for(int i = 0; i < MAX; i++) {
				value[i] = B.value[i];
			}
		}

		bool operator==(const Bignum& B) {
			for(int i = 0; i < MAX; i++) {
				if(this->value[i] != B.value[i]) {
					return false;
				}
			}
			return true;
		}

		bool operator!=(const Bignum& B) {
			for(int i = 0; i < MAX; i++) {
				if(this->value[i] != B.value[i]) {
					return true;
				}
			}
			return false;
		}
};

inline Bignum power(Bignum base, int power) {
	Bignum result;
	result = 1;
	while (power > 0) {
		if (power & 1) {
			result = result * base;
		}
		power >>= 1;
		base = base * base;
	}
	return result;
}

// return A mod (10 ^ k)
inline Bignum tenMod(Bignum A, int k) {
	Bignum res;
	res = A;
	for(int i = A.getMax() - 1; i >= k; i--) {
		res.writeBit(i, 0);
	}
	return res;
}
