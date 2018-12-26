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

}

void Calc::MainPage::Button_Click_plus(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}


void Calc::MainPage::Button_Click_minus(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

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

