#include <string>
#include <iostream>
#include <algorithm>

class Text
{
public:
    virtual void render(const std::string &data) const
    {
        std::cout << data;
    }
    virtual void render(const std::string &link, const std::string &data)
    {
        std::cout << data;
    }
};

class DecoratedText : public Text
{
public:
    explicit DecoratedText(Text *text) : text_(text) {}
    Text *text_;
};

class Paragraph : public DecoratedText
{
public:
    explicit Paragraph(Text *text) : DecoratedText(text) {}
    void render(const std::string &data) const
    {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Link : public DecoratedText
{
public:
    explicit Link(Text *text) : DecoratedText(text) {}
    void render(const std::string &link, const std::string &text) const
    {
        std::cout << "<a href=" << link << ">";
        text_->render(link, text);
        std::cout << "</a>";
    }
};

class Reversed : public DecoratedText
{
public:
    explicit Reversed(Text *text) : DecoratedText(text) {}
    void render(const std::string &data) const
    {
        std::string copy(data);
        std::reverse(copy.begin(), copy.end());
        std::cout << copy;
    }
};

class ItalicText : public DecoratedText
{
public:
    explicit ItalicText(Text *text) : DecoratedText(text) {}
    void render(const std::string &data) const
    {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText
{
public:
    explicit BoldText(Text *text) : DecoratedText(text) {}
    void render(const std::string &data) const
    {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

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
