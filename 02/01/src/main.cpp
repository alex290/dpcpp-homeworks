#include <iostream>
#include "paragraph.h"
#include "reversed.h"
#include "link.h"

int main()
{
    auto text = new Text();
    auto text_block = new Paragraph(text);
    text_block->render("Hello world");

    auto text_block_r = new Reversed(new Text());
    text_block_r->render("Hello world");

    auto text_block_a = new Link(new Text());
    text_block_a->render("netology.ru", "Hello world");

    delete text_block_a;
    delete text_block_r;
    delete text_block;
    delete text;

    return 0;
}
