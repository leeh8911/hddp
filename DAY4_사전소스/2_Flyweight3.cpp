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

// Image ��ü�� ������ ������ ������ Ŭ��������!
class ImageFactory {
	MAKE_SINGLETON(ImageFactory)

	std::map<std::string, Image*> image_map;
public:
	Image* Create(const std::string& url) {

		// image_map["Key"]�� ������, "Key"���� ���� ���, "Key"�� ������
		// ���� "Key"�� �ִ����� ���縦 ���ؼ�, �Ʒ�ó�� �ϴ°� ������
		Image* img = nullptr;
		auto ret = image_map.find(url);

		if (ret == image_map.end()) {
			img = new Image(url);
			image_map[url] = img;
		}
		// ���� : C++20���ʹ� ���� ��� �Լ��� �߰��� (contain)
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



