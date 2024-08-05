#include "string.h"

// Constructor implementations
String::String() : size(0) {
    data = new char[size + 1];
    data[0] = '\0';
}

String::String(const String &str) : size(str.size) {
    data = new char[size + 1];
    strcpy(data, str.data);
}

String::String(const char* str) {
    size = strlen(str);
    data = new char[size + 1];
    strcpy(data, str);
}

// Pure virtual function implementations
StringArray String::split(const char *delimiters) const {
    std::vector<std::string> result;
    int delisum = 0;
    char* token;
    String local(this->data);
    token = strtok(local.data, delimiters);
    while (token != NULL) {
        delisum++;
        result.push_back(token);
        token = strtok(NULL, delimiters);
    }

    // Create a StringArray object
    StringArray Array;
    for (int i = 0; i < delisum; ++i) {
        GenericString* current = make_string(result[i].c_str());
        Array.Push(current);
    }
    return Array;
}

GenericString& String::operator=(const char *str) {
    if (strcmp(data, str) == 0) {
        return *this;
    }

    delete[] data;
    size = strlen(str);
    data = new char[size + 1];
    strcpy(data, str);
    return *this;
}

GenericString& String::trim() {
    int begin = 0;
    int end = size - 1;

    while (begin <= end && isspace(data[begin])) {
        begin++;
    }
    while (end >= begin && isspace(data[end])) {
        end--;
    }

    int newSize = end - begin + 1;
    char* tempData = new char[newSize + 1];
    strncpy(tempData, data + begin, newSize);
    tempData[newSize] = '\0';

    delete[] data;
    data = tempData;
    size = newSize;

    return *this;
}

bool String::operator==(const GenericString &other) const {
    const String* temp = dynamic_cast<const String*>(&other);
    if (temp) {
        return strcmp(data, temp->data) == 0;
    }
    return false;
}

bool String::operator==(const char *other) const {
    return strcmp(data, other) == 0;
}

int String::to_integer() const {
    if (size == 0) {
        return 0;
    }
    try {
        return std::stoi(data);
    } catch (const std::out_of_range&) {
        return 0;
    }
}


String& String::as_string() {
    return *this;
}

const String& String::as_string() const {
    return *this;
}

GenericString* make_string(const char *str) {
    String* my_str = new String(str);
    return my_str;
}

String::~String() {
    delete[] data;
}


