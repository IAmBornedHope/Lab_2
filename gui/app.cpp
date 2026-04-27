#include "app.hpp"

MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, wxString::FromUTF8("Лабораторная работа № 2"), wxDefaultPosition, wxSize(1200, 800)) {
    current_sequence_id = 0;
    // Панель и сайзеры
    wxPanel* main_panel = new wxPanel(this);
    wxBoxSizer* main_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* left_sizer = new wxBoxSizer(wxVERTICAL);

    // Заголовки
    wxStaticText* title = new wxStaticText(main_panel, wxID_ANY, wxString::FromUTF8("Выбор операции"));
    title->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    left_sizer->Add(title, 0, wxALL | wxCENTER, 10);

    wxStaticText* active_title = new wxStaticText(main_panel, wxID_ANY, wxString::FromUTF8("Активная последовательность:"));
    left_sizer->Add(active_title, 0, wxLEFT | wxTOP, 5);

    // Выбор активной
    object_selector = new wxComboBox(main_panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0, nullptr, wxCB_READONLY);
    for (const auto& name : sequence_names) {
        object_selector->AppendString(name);
    }

    object_selector->SetSelection(0);
    object_selector->Bind(wxEVT_COMBOBOX, &MyFrame::on_select_object, this);
    left_sizer->Add(object_selector, 0, wxEXPAND | wxALL, 5);
    left_sizer->Add(new wxStaticLine(main_panel), 0, wxEXPAND | wxALL, 10);

    // Ввод индекса и значения
    wxStaticText* value_title = new wxStaticText(main_panel, wxID_ANY, wxString::FromUTF8("Значение / индекс"));
    left_sizer->Add(value_title, 0, wxLEFT | wxTOP, 5);

    input_value = new wxTextCtrl(main_panel, wxID_ANY, "");
    input_value->SetHint(wxString::FromUTF8("Введите целое число"));
    left_sizer->Add(input_value, 0, wxEXPAND | wxALL, 5);

    input_index = new wxTextCtrl(main_panel, wxID_ANY, "");
    input_index->SetHint(wxString::FromUTF8("Индекс или start-end"));
    left_sizer->Add(input_index, 0, wxEXPAND | wxALL, 5);

    // Сетка из кнопок
    wxGridSizer* button_grid = new wxGridSizer(3, 2, 5, 5);

    wxButton* button_ap = new wxButton(main_panel, wxID_ANY, "Append");
    button_ap->Bind(wxEVT_BUTTON, &MyFrame::on_append, this);
    button_grid->Add(button_ap, 1, wxEXPAND);

    wxButton* button_pr = new wxButton(main_panel, wxID_ANY, "Prepend");
    button_pr->Bind(wxEVT_BUTTON, &MyFrame::on_prepend, this);
    button_grid->Add(button_pr, 1, wxEXPAND);

    wxButton* button_get_at = new wxButton(main_panel, wxID_ANY, "Get at");
    button_get_at->Bind(wxEVT_BUTTON, &MyFrame::on_get_at, this);
    button_grid->Add(button_get_at, 1, wxEXPAND);

    wxButton* button_in = new wxButton(main_panel, wxID_ANY, "Insert at");
    button_in->Bind(wxEVT_BUTTON, &MyFrame::on_insert_at, this);
    button_grid->Add(button_in, 1, wxEXPAND);

    wxButton* button_gl = new wxButton(main_panel, wxID_ANY, "Get length");
    button_gl->Bind(wxEVT_BUTTON, &MyFrame::on_get_length, this);
    button_grid->Add(button_gl, 1, wxEXPAND);

    wxButton* button_clear = new wxButton(main_panel, wxID_ANY, "Clear");
    button_clear->Bind(wxEVT_BUTTON, &MyFrame::on_clear, this);
    button_grid->Add(button_clear, 1, wxEXPAND);

    left_sizer->Add(button_grid, 0, wxEXPAND | wxALL, 5);
    // Пустая линия-разделитель
    left_sizer->Add(new wxStaticLine(main_panel), 0, wxEXPAND | wxALL, 10);


    // Выбор целевой последовательности
    wxStaticText* target_title = new wxStaticText(main_panel, wxID_ANY, wxString::FromUTF8("Целевая последовательность"));
    left_sizer->Add(target_title, 0, wxLEFT | wxTOP, 5);
    target_selector = new wxComboBox(main_panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0, nullptr, wxCB_READONLY);
    for (const auto& name : sequence_names) {
        target_selector->AppendString(name);
    }
    target_selector->SetSelection(1);
    left_sizer->Add(target_selector, 0, wxEXPAND | wxALL, 5);

    // Нижний горизонтальный блок кнопок
    wxBoxSizer* down_buttons = new wxBoxSizer(wxHORIZONTAL);

    wxButton* button_con = new wxButton(main_panel, wxID_ANY, wxString::FromUTF8("Concat"));
    button_con->Bind(wxEVT_BUTTON, &MyFrame::on_concat, this);
    down_buttons->Add(button_con, 1, wxEXPAND | wxRIGHT, 5);

    wxButton* button_sub = new wxButton(main_panel, wxID_ANY, wxString::FromUTF8("Subsequence"));
    button_sub->Bind(wxEVT_BUTTON, &MyFrame::on_subsequence, this);
    down_buttons->Add(button_sub, 1, wxEXPAND);

    left_sizer->Add(down_buttons, 0, wxEXPAND | wxALL, 5);
    left_sizer->AddStretchSpacer();
    // Левое табло в основное пространство
    main_sizer->Add(left_sizer, 0, wxEXPAND | wxALL, 10);


    output_field = new wxTextCtrl(main_panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize,
                                wxTE_READONLY | wxTE_MULTILINE | wxTE_WORDWRAP | wxBORDER_SIMPLE);
    output_field->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    main_sizer->Add(output_field, 1, wxEXPAND | wxALL, 10);

    main_panel->SetSizer(main_sizer);
    Centre();

    refresh_output();
}

MyFrame::~MyFrame() {}

Sequence<int>* MyFrame::get_sequence(size_t id) {
    switch (id) {
        case 0: return &array_1;
        case 1: return &array_2;
        case 2: return &list_1;
        case 3: return &list_2;
        default: return nullptr;
    }
}

bool MyFrame::get_input(wxTextCtrl* ctrl, int& value) {
    wxString val_inside = ctrl->GetValue();
    if (val_inside.IsEmpty()) {
        return false;
    }
    int v;
    if (!val_inside.ToInt(&v)) return false;
    value = static_cast<int>(v);
    return true;
}

void MyFrame::refresh_output()
{
    Sequence<int>* sequence = get_sequence(current_sequence_id);
    if (!sequence) {
        output_field->SetValue("");
        return;
    }
    try {
        std::string str = sequence_to_string(sequence);
        output_field->SetValue(str);
    } catch (const Exception& error) {
        output_field->SetValue(wxString::FromUTF8("Ошибка: ") + error.what());
    } 
}





void MyFrame::on_select_object(wxCommandEvent& event) {
    current_sequence_id = object_selector->GetSelection();
    refresh_output();
}

void MyFrame::on_append(wxCommandEvent& event) {
    Sequence<int>* sequence = get_sequence(current_sequence_id);
    if (!sequence) return;
    int value;

    if (!get_input(input_value, value)) {
        wxMessageBox(wxString::FromUTF8("Введите целое число."), wxString::FromUTF8("Ошибка!"), wxOK | wxICON_ERROR);
        return;
    }

    try {
        sequence->append(value);
        refresh_output();
        //Clear из wxwidgets!!!
        input_value->Clear();
    } catch (const Exception& error) {
        wxMessageBox(wxString::FromUTF8(error.what()), wxString::FromUTF8("Ошибка!"), wxOK | wxICON_ERROR);
    }
}

void MyFrame::on_prepend(wxCommandEvent& event) {
    Sequence<int>* sequence = get_sequence(current_sequence_id);
    if (!sequence) return;
    int value;

    if (!get_input(input_value, value)) {
        wxMessageBox(wxString::FromUTF8("Введите целое число."), wxString::FromUTF8("Ошибка!"), wxOK | wxICON_ERROR);
        return;
    }
    
    try {
        sequence->prepend(value);
        refresh_output();
        input_value->Clear();
    } catch (const Exception& error) {
        wxMessageBox(wxString::FromUTF8(error.what()), wxString::FromUTF8("Ошибка!"), wxOK | wxICON_ERROR);
    } 
}

void MyFrame::on_insert_at(wxCommandEvent& event) {
    Sequence<int>* sequence = get_sequence(current_sequence_id);
    if (!sequence) return;
    int value;
    int index;

    if (!get_input(input_value, value)) {
        wxMessageBox(wxString::FromUTF8("Введите целое число."), wxString::FromUTF8("Ошибка!"), wxOK | wxICON_ERROR);
        return;
    }


    if (!get_input(input_index, index)) {
        wxMessageBox(wxString::FromUTF8("Введите корректный индекс."), wxString::FromUTF8("Ошибка!"), wxOK | wxICON_ERROR);
        return;
    }

    try {
        sequence->insert_at(value, static_cast<size_t>(index));
        refresh_output();
    } catch (const Exception& error) {
        wxMessageBox(wxString::FromUTF8(error.what()), wxString::FromUTF8("Ошибка!"), wxOK | wxICON_ERROR);
    } 
}

void MyFrame::on_get_length(wxCommandEvent& event) {
    Sequence<int>* sequence = get_sequence(current_sequence_id);
    if (!sequence) return;
    
    try {
        size_t length = sequence->get_length();
        wxMessageBox(wxString::Format(wxString::FromUTF8("Длина последовательности: %zu"), length),
                                wxString::FromUTF8("Информация"), wxOK | wxICON_INFORMATION);

    } catch (const Exception& error) {
        wxMessageBox(wxString::FromUTF8(error.what()), wxString::FromUTF8("Ошибка!"), wxOK | wxICON_ERROR);
    } 
}

void MyFrame::on_get_at(wxCommandEvent& event) {
    Sequence<int>* sequence = get_sequence(current_sequence_id);
    if (!sequence) return;
    int index;

    if (!get_input(input_index, index)) {
        wxMessageBox(wxString::FromUTF8("Введите корректный индекс."), wxString::FromUTF8("Ошибка!"), wxOK | wxICON_ERROR);
        return;
    }

    int value;
    try {
        value = sequence->get(static_cast<size_t>(index));
        wxMessageBox(wxString::Format(wxString::FromUTF8("Элемент [%d]: %d"), index, value), wxString::FromUTF8("Результат"), wxOK | wxICON_INFORMATION);
    } catch (const Exception& error) {
        wxMessageBox(wxString::FromUTF8(error.what()), wxString::FromUTF8("Ошибка!"), wxOK | wxICON_ERROR);
    } 
}

void MyFrame::on_concat(wxCommandEvent& event) {
    size_t first_id = current_sequence_id;
    size_t second_id = target_selector->GetSelection();

    if (first_id == second_id) {
        wxMessageBox(wxString::FromUTF8("Выберите разные последовательности"), wxString::FromUTF8("Ошибка!"), wxOK | wxICON_ERROR);
        return;
    }

    Sequence<int>* first = get_sequence(first_id);
    Sequence<int>* second = get_sequence(second_id);
    if (!first || !second) return;

    try {
        Sequence<int>* result = first->concat(second);
        std::string result_string = sequence_to_string(result);
        delete result;
        
        output_field->SetValue(wxString::FromUTF8("Результат конкатенации: ") + result_string);
    } catch (const Exception& error) {
        wxMessageBox(wxString::FromUTF8(error.what()), wxString::FromUTF8("Ошибка!"), wxOK | wxICON_ERROR);
    } 
}

void MyFrame::on_subsequence(wxCommandEvent& event) {
    Sequence<int>* sequence = get_sequence(current_sequence_id);
    if (!sequence) return;

    wxString range = input_index->GetValue();
    int separator_pos = range.Find('-');

    if (separator_pos == wxNOT_FOUND) {
        wxMessageBox(wxString::FromUTF8("Введите корректно. (например, 0-2)"), wxString::FromUTF8("Ошибка!"), wxOK | wxICON_ERROR);
        return;
    }

    int start, end;
    if (!range.Left(separator_pos).ToInt(&start) || !range.Mid(separator_pos + 1).ToInt(&end)) {
        wxMessageBox(wxString::FromUTF8("Неверные числа!"), wxString::FromUTF8("Ошибка!"), wxOK | wxICON_ERROR);
        return;
    }
    
    try {
        Sequence<int>* sub_sequence = sequence->get_subsequence(static_cast<size_t>(start), static_cast<size_t>(end));
        std::string result_string = sequence_to_string(sub_sequence);
        delete sub_sequence;
        output_field->SetValue(wxString::FromUTF8("Подпоследовательность: ") + result_string);
    } catch (const Exception& error) {
        wxMessageBox(wxString::FromUTF8(error.what()), wxString::FromUTF8("Ошибка!"), wxOK | wxICON_ERROR);
    } 
}

void MyFrame::on_clear(wxCommandEvent& event)
{
    Sequence<int>* sequence = get_sequence(current_sequence_id);
    if (!sequence) return;

    try {
        sequence->clear();
        refresh_output();
    } catch (const Exception& error) {
        wxMessageBox(wxString::FromUTF8(error.what()), wxString::FromUTF8("Ошибка"), wxOK | wxICON_ERROR);
    }
}
