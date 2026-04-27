#include "app.hpp"

class MyApp : public wxApp
{
public:
    bool OnInit() override;
};


int run_gui() {
    MyApp* app = new MyApp();
    return wxEntry();
}

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}

