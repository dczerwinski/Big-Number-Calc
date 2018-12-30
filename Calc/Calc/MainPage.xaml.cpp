//
// MainPage.xaml.cpp
// Implementacja klasy MainPage.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <string>

using namespace Calc;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;



//Szablon elementu Pusta strona jest udokumentowany na stronie https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x415



MainPage::MainPage()
{
	this->current_display = "0";
	InitializeComponent();
	this->TB_result->Text = current_display;
	arg1 =L"e";
	arg2 = L"e";
	action = 'e';
	
}


void Calc::MainPage::Button_Click_0(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (this->current_display != "0")this->current_display += "0";
	Update_TB_result();
}


void Calc::MainPage::Button_Click_7(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->current_display += "7";
	Update_TB_result();
}


void Calc::MainPage::Button_Click_8(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->current_display += "8";
	Update_TB_result();
}


void Calc::MainPage::Button_Click_9(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->current_display += "9";
	Update_TB_result();
}


void Calc::MainPage::Button_Click_6(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->current_display += "6";
	Update_TB_result();
}


void Calc::MainPage::Button_Click_5(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->current_display += "5";
	Update_TB_result();
}


void Calc::MainPage::Button_Click_4(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->current_display += "4";
	Update_TB_result();
}


void Calc::MainPage::Button_Click_1(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->current_display += "1";
	Update_TB_result();
}


void Calc::MainPage::Button_Click_2(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->current_display += "2";
	Update_TB_result();
}


void Calc::MainPage::Button_Click_3(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->current_display += "3";
	Update_TB_result();
}


void Calc::MainPage::Button_Click_result(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	do_calc();
	this->current_display = ref new String(std::wstring(L"0").c_str());
	arg2 = L'e';
	arg1 = L'e';
	action = 'e';
}

void Calc::MainPage::Button_Click_plus(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (action != 'e')do_calc();
	current_display = this->TB_result->Text;
	auto temp = current_display->Begin();
	arg1 = temp;
	this->current_display = ref new String(std::wstring(L"0").c_str());
	action = '+';
	Update_TB_result();
}


void Calc::MainPage::Button_Click_minus(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	throw ref new Platform::NotImplementedException();
}

void Calc::MainPage::do_calc()
{
	switch (action)
	{
	case '+':
	{
		current_display = this->TB_result->Text;
		auto temp = current_display->Begin();
		arg2 = temp;
		add();
		Update_TB_result();
		arg2 = L'e';
		arg1 = L'e';
		action = 'e';
	}
		break;
	default:
		break;
	}
}

void Calc::MainPage::Update_TB_result()
{
	auto it = this->current_display->Begin();
	if (this->current_display->Length() > 1 && it[0] == '0')
	{
		std::wstring temp = it;
		temp.erase(0, 1);
		this->current_display = ref new String(temp.c_str());
	}
	this->TB_result->Text = current_display;
}


void Calc::MainPage::add()
{
	if (arg1 == L"e" || arg2 == L"e")throw ref new Platform::NotImplementedException();


	while (arg1.length() < arg2.length())
		arg1.insert(0, L"0");

	while (arg2.length() < arg1.length())
		arg2.insert(0, L"0");


	std::wstring temp_result=L"";
	std::reverse(arg1.begin(), arg1.end());
	std::reverse(arg2.begin(), arg2.end());

	int temp = 0;
	int rest = 0;
	for (int i = 0; i <arg1.length(); i++) 
	{
		temp = arg1[i]-'0'+arg2[i]-'0'+rest;
		rest = 0;
		if (temp > 9)
		{
			rest = temp / 10;
			temp = temp % 10;
		}
		temp_result += wchar_t(temp+'0');
	}
	
	if(rest !=0)temp_result += wchar_t(rest + '0');

	std::reverse(temp_result.begin(), temp_result.end());

	this->current_display = ref new String(temp_result.c_str());
}


void Calc::MainPage::sub()
{
	throw ref new Platform::NotImplementedException();
}

