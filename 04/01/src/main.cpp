#include <fstream>
#include <iostream>

class Printable
{
public:
    virtual std::string printAs() { return ""; };
    virtual void setData(const std::string &data) { data_ = data; };

protected:
    std::string data_;
};

class PrintableHtml : public Printable
{
public:
    std::string printAs()
    {
        return "<html>" + data_ + "<html/>";
    };
};

class PrintableText : public Printable
{
public:
    std::string printAs()
    {
        return data_;
    };
};

class PrintableJSON : public Printable
{
public:
    std::string printAs()
    {
        return "{ \"data\": \"" + data_ + "\"}";
    }
};

// class Data : public Printable
// {
// public:
//     enum class Format
//     {
//         kText,
//         kHTML,
//         kJSON
//     };

//     Data(std::string data, Format format)
//         : data_(std::move(data)), format_(format) {}

//     std::string printAsHTML() const override
//     {
//         if (format_ != Format::kHTML) {
//             throw std::runtime_error("Invalid format!");
//         }
//         return "<html>" + data_ + "<html/>";
//     }
//     std::string printAsText() const override
//     {
//         if (format_ != Format::kText) {
//             throw std::runtime_error("Invalid format!");
//         }
//         return data_;
//     }
//     std::string printAsJSON() const override
//     {
//         if (format_ != Format::kJSON) {
//             throw std::runtime_error("Invalid format!");
//         }
//         return "{ \"data\": \"" + data_ + "\"}";
//     }

// private:
//     std::string data_;
//     Format format_;
// };

void saveTo(std::ofstream &file, Printable *printable)
{
    // switch (format)
    // {
    // case Data::Format::kText:
    //     file << printable.printAsText();
    //     break;
    // case Data::Format::kJSON:
    //     file << printable.printAsJSON();
    //     break;
    // case Data::Format::kHTML:
    //     file << printable.printAsHTML();
    //     break;
    // }
    file << printable->printAs();
}

void saveToAs(std::ofstream &file, Printable *printable)
{
    saveTo(file, printable);
}

// void saveToAsHTML(std::ofstream &file, const Printable& printable) {
//     saveTo(file, printable, Data::Format::kHTML);
// }

// void saveToAsJSON(std::ofstream &file, const Printable& printable) {
//     saveTo(file, printable, Data::Format::kJSON);
// }

// void saveToAsText(std::ofstream &file, const Printable& printable) {
//     saveTo(file, printable, Data::Format::kText);
// }

int main()
{
    std::ofstream file;

    PrintableHtml html;
    html.setData("HTML text");

    PrintableText text;
    text.setData("text");

    PrintableJSON json;
    json.setData("JSON text");

    saveToAs(file, &html);

    saveToAs(file, &text);

    saveToAs(file, &json);
}