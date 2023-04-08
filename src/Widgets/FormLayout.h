#include "Layout.h"
#include <QtWidgets/QFormLayout>

class FormLayout : public Layout
{
private:
    QFormLayout *native;

public:
    inline static const std::string CLASSPATH = "Qt\\Widgets\\FormLayout";

    void __construct(Php::Parameters &params);
    void addRow(Php::Parameters &params);

    static Php::Class<FormLayout> _DEFINITION()
    {
        Php::Class<FormLayout> definition(FormLayout::CLASSPATH.c_str());

        definition.method<&FormLayout::__construct>("__construct");
        definition.method<&FormLayout::addRow>("addRow", {
            Php::ByVal("label", Php::Type::Object, true),
            Php::ByVal("parent", Php::Type::Object, false)
        });

        return definition;
    }
};