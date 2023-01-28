#include <iostream>
using namespace std;
class LIST_ABD {
	int *original_ptr;
	int *helping_ptr;
	int original_size;
	int helping_size;
public:
	LIST_ABD() {
		original_size = 5;
		original_ptr = new int[5];
		helping_ptr = NULL;
		helping_size = 0;
	}
	bool DELETE_ELEMENT(int value) {
		for (int i = 0; i < original_size; i++) {
			if (original_ptr[i] == value) {
				original_ptr[i] = 0;
				return true;
			}
		}
		return false;
	}
	bool SEARCH_ELEMENT(int value) {
		for (int i = 0; i < original_size; i++) {
			if (original_ptr[i] == value) {
				cout << "FOUND SUCCESSFULLY."<<endl;
				return 1;
			}
		}
		cout << "NOT FOUND SUCCESSFULLY."<<endl;
		return 0;
	}
	void ADD_ELEMENT(int number) {
		if (helping_size< original_size) {
			original_ptr[helping_size] = number;
			helping_size++;
		}
		else
		{
			original_size=original_size * 2;
			helping_ptr = new int[original_size];
			for (int i = 0; i < original_size; i++) {
				helping_ptr[i] = original_ptr[i];
				delete[] original_ptr;
				original_ptr = helping_ptr;
				original_ptr[helping_size] = number;
				helping_size++;
	}
		}
	}
	void DISPLAY() {
		for (int i = 0; i <helping_size; i++) {
			cout << original_ptr[i] << " ";
		}
	}
	~LIST_ABD() {
		delete[] original_ptr,helping_ptr;
	}
};
int main()
{
	LIST_ABD l;
	l.ADD_ELEMENT(5);
	l.DISPLAY();
	l.SEARCH_ELEMENT(5);
	l.DELETE_ELEMENT(5);
	l.DISPLAY();
	return 0;
}
