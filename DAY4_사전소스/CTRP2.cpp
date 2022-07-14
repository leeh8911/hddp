template<typename T>
class LimitCount {
	static int cnt;
public:
	LimitCount() { if (++cnt > 5) throw 1; }
	~LimitCount() { --cnt; }
};

template<typename T> int LimitCount<T>::cnt = 0;

class Mouse : public LimitCount<Mouse> {

};

class Keyboard : public LimitCount<Keyboard> {

};


int main() {
	LimitCount<int> c1[2];
	Mouse c2[2];
	Keyboard c3[2];
}