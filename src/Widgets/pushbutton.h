#include "widget.h"
#include<phpcpp.h>
#include<QtWidgets/QPushButton>

class PushButton : public Widget
{
private:
    QPushButton *button;

public:
    void __construct(Php::Parameters &params);
    void onClicked(Php::Parameters &params);
    void onPressed(Php::Parameters &params);
    void onReleased(Php::Parameters &params);

    static Php::Class<PushButton> _DEFINITION()
    {
        Php::Class<PushButton> pushbutton("Qt\\Widgets\\PushButton");
        pushbutton.method<&PushButton::__construct>("__construct", {
            Php::ByVal("name", Php::Type::String, true),
            Php::ByRef("parent", Php::Type::Object, true)
        });

        pushbutton.method<&PushButton::onPressed>("onPressed", {Php::ByVal("callback", Php::Type::Callable, true)});
        pushbutton.method<&PushButton::onClicked>("onClicked", {Php::ByVal("callback", Php::Type::Callable, true)});
        pushbutton.method<&PushButton::onReleased>("onReleased", {Php::ByVal("callback", Php::Type::Callable, true)});

        return pushbutton;
    }
};