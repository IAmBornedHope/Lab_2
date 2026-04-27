#pragma once
#include <wx/wx.h>
#include <wx/combobox.h>
#include <wx/statline.h>
#include <string>
#include <vector>
#include "../sequence/Sequence.hpp"
#include "../array_sequence/ArraySequence.hpp"
#include "../array_sequence/MutableArraySequence.hpp"
#include "../list_sequence/MutableListSequence.hpp"
#include "../list_sequence/ListSequence.hpp"
#include "../exceptions/Exceptions.hpp" 

template <typename T>
std::string sequence_to_string(Sequence<T>* sequence) {
    if (!sequence || sequence->get_length() == 0) return "";

    std::string result;
    size_t length = sequence->get_length();

    for (size_t index = 0; index < length; ++index) {
        result += std::to_string(sequence->get(index)); 
        if (index != length - 1) {
            result += ", ";
        }
    }
    return result;
}

class MyFrame: public wxFrame {
public:
    MyFrame();
    ~MyFrame();
private:
    void on_select_object(wxCommandEvent& event);
    void on_append(wxCommandEvent& event);
    void on_prepend(wxCommandEvent& event);
    void on_insert_at(wxCommandEvent& event);
    void on_get_length(wxCommandEvent& event);
    void on_get_at(wxCommandEvent& event);
    void on_subsequence(wxCommandEvent& event);
    void on_concat(wxCommandEvent& event);
    void on_clear(wxCommandEvent& event);

    void refresh_output();
    Sequence<int>* get_sequence(size_t id);
    bool get_input(wxTextCtrl* ctrl, int& value);
    size_t current_sequence_id;

    MutableArraySequence<int> array_1;
    MutableArraySequence<int> array_2;
    MutableListSequence<int> list_1;
    MutableListSequence<int> list_2;

    const std::vector<std::string> sequence_names = {"ArraySequence 1", "ArraySequence 2", "ListSequence 1", "ListSequence 2"};

    wxComboBox* object_selector;
    wxComboBox* target_selector;

    wxTextCtrl* input_value;
    wxTextCtrl* input_index;
    wxTextCtrl* output_field;

};

int run_gui();

