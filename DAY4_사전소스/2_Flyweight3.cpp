// 3_Flyweight - 167
#include <iostream>
#include <string>
#include <map>

#include "helper.h"

class Image
{
	std::string image_url;

	Image(std::string url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}

public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	friend class ImageFactory;
};

// Image 객체의 생성과 관리는 별도의 클래스에서!
class ImageFactory {
	MAKE_SINGLETON(ImageFactory)

	std::map<std::string, Image*> image_map;
public:
	Image* Create(const std::string& url) {

		// image_map["Key"]로 적으면, "Key"값이 없는 경우, "Key"가 생성됨
		// 단지 "Key"가 있는지만 조사를 위해선, 아래처럼 하는게 좋ㅇ므
		Image* img = nullptr;
		auto ret = image_map.find(url);

		if (ret == image_map.end()) {
			img = new Image(url);
			image_map[url] = img;
		}
		// 참고 : C++20부터는 좋은 멤버 함수가 추가됨 (contain)
		// if (!image_map.contain(url)) {}
		return img;
	}

};
int main()
{
	ImageFactory& factory = ImageFactory::getInstance();

	Image* img1 = factory.Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.Create("www.naver.com/a.png");
	img2->Draw();

	std::cout << img1 << std::endl;
	std::cout << img2 << std::endl;
}



