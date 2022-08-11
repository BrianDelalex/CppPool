#include "ITable.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"
#include <iostream>
#include "PapaXmasConveyor.hpp"
#include "PapaXmasTable.hpp"
#include "TableRand.hpp"
#include "Boxes.hpp"


ITable *createTable ()
{
    ITable *table = new PapaXmasTable;
    table->put(new Teddy);
    table->put(new LittlePony);
    table->put(new Teddy);
    table->put(new Teddy);
    table->put(new LittlePony);
    table->put(new Teddy);
    table->put(new Teddy);
    table->put(new LittlePony);
    table->put(new LittlePony);
    table->put(new Teddy);
    return (table);
}

IConveyorBelt *createConveyorBelt()
{
    IConveyorBelt *conveyor = new PapaXmasConveyor;
    conveyor->put(new Box());
    return (conveyor);
}

int main(void)
{
    ITable *table = createTable();
    std::string *str = table->look();
    std::cout << "----List of Object on the table----" << std::endl;
    for (int i = 0;str[i]!= ""; i++) {
        std::cout << i << ": " << str[i] << std::endl;
    }
    table->take("cuddles");
    table->take("cuddles");
    str = table->look();
    for (int i = 0;str[i]!= ""; i++) {
        std::cout << i << ": " << str[i] << std::endl;
    }
    IConveyorBelt *conveyor = createConveyorBelt();
    Object *conv = conveyor->take();
    if (conv != nullptr)
        std::cout << "CONVOYEr OBJ:" << conv->getTitle() << std::endl;
    std::cout << "---- RandTable ----" << std::endl;
    TableRand trand;
    std::string *nstr = trand.look();
    std::cout << "----List of Object on the table----" << std::endl;
    for (int i = 0; i != 10; i++) {
        std::cout << i << ": " << nstr[i] << std::endl;
    }
}