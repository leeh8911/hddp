// 2_Flyweight - 167
#include <iostream>
#include <string>
#include <map>

class Image
{
	std::string image_url;
	Image(std::string url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}

public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	// Image ��ü�� ����� static ��� �Լ�
	// => ���� ��ü�� �Ʒ� �Լ��� ���ؼ��� ���� �� ����
	// => ��ü�� "�Ѱ�"������ ����ٴ� ���� ������ ��� ��ü�� "����"�� �� �ִ�
	//		��ȸ�� ����� ��
	static std::map<std::string, Image*> image_map;

	static Image* Create(const std::string& url) {

		if (image_map[url] == nullptr) {
			Image* img = new Image(url);
			image_map[url] = img;
		}

		return image_map[url];
	}

	static int image_count() { return image_map.size(); }
};

std::map<std::string, Image*> Image::image_map;

int main()
{
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

	std::cout << img1 << std::endl;
	std::cout << img2 << std::endl;
}



