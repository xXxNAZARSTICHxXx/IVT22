#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include "calccycleNAME.h"
using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::BlankApp2::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainPage::Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
    {
        OutputBox.Text = (calccycleMODULE::FractionCounter(InputBox.text).ToString();
    }
}

