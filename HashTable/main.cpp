#include <string>
#include <iostream>
#include <unordered_map>

class URLService
{
	//Modern C++에서는 typedef 대신 using 사용
	using ActualURL = std::string;
	using TinyURL = std::string;
private:
	std::unordered_map<TinyURL, ActualURL> data;

public:
	std::pair<bool, ActualURL> lookup(const TinyURL& url) const
	{
		std::unordered_map<TinyURL, ActualURL>::const_iterator it = data.find(url);
		if (it == data.end())
		{
			return std::make_pair(false, std::string());
		}
		else
		{
			return std::make_pair(true, it->second);
		}
	}
	
	bool registerURL(const ActualURL& actualURL, const TinyURL& tinyURL)
	{
		bool found = lookup(tinyURL).first;
		if (found)
		{
			return false;
		}

		data[tinyURL] = actualURL;
		return true;
	}

	bool deregisterURL(const TinyURL& tinyURL)
	{
		bool found = lookup(tinyURL).first;
		if (found)
		{
			data.erase(tinyURL);
			return true;
		}
		return false;
	}

	void printURLs() const
	{
		//???
		for (const auto& entry : data)
		{
			std::cout << entry.first << " -> " << entry.second << std::endl;
		}
		std::cout << std::endl;
	}
};

int main()
{
	URLService* service = new URLService();

	if (service->registerURL("https://www.gilbut.co.kr/book/view?bookcode=BN002245", "https://py_dojang"))
	{
		std::cout << "https://py_dojang 등록" << std::endl;
	}
	else
	{
		std::cout << "https://py_dojang 등록 실패" << std::endl;
	}

	if (service->registerURL("https://www.gilbut.co.kr/book/view?bookcode=BN001484", "https://c_dojang"))
	{
		std::cout << "https://c_dojang 등록" << std::endl;
	}
	else
	{
		std::cout << "https://c_dojang 등록 실패" << std::endl;
	}

	if (service->registerURL("https://www.gilbut.co.kr/book/view?bookcode=BN002402", "https://opencv4"))
	{
		std::cout << "https://opencv4 등록" << std::endl;
	}
	else
	{
		std::cout << "https://opencv4 등록 실패" << std::endl;
	}

	std::pair<bool, std::string> pythonBook = service->lookup("https://py_dojang");

	if (pythonBook.first)
	{
		std::cout << "https://py_dojang 원본 URL: " << pythonBook.second << std::endl;
	}
	else
	{
		std::cout << "https://py_dojang 원본 URL을 찾을 수 없습니다." << std::endl;
	}

	std::pair<bool, std::string> cppBook = service->lookup("https://cpp_dojang");
	if (cppBook.first)
	{
		std::cout << "https://cpp_dojang 원본 URL: " << cppBook.second << std::endl;
	}
	else
	{
		std::cout << "https://cpp_dojang 원본 URL을 찾을 수 없습니다." << std::endl;
	}

	//삭제
	if (service->deregisterURL("https://c_dojang"))
	{
		std::cout << "c_dojang 책 URL 등록 해제" << std::endl;
	}
	else
	{
		std::cout << "c_dojang 책 URL 등록 해제 실패" << std::endl;
	}

	std::pair<bool, std::string> findQtBook = service->lookup("https://c_dojang");

	if (findQtBook.first)
	{
		std::cout << "https://c_dojang 원본 URL: " << findQtBook.second << std::endl;
	}
	else
	{
		std::cout << "https://c_dojang 원본 URL을 찾을 수 없습니다." << std::endl;
	}

	std::cout << "등록된 URL 리스트:" << std::endl;
	service->printURLs();

	delete service;
}