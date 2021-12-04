#include "MyForm.h"


namespace simchat {

    using namespace System;
    using namespace System::Windows::Forms;

    // How many lines we print to the history
    int LINES_TO_PRINT = 10;

    // Our inside variables.
    struct sentMessage {
        std::string username;
        std::string message;
    };

    std::vector<sentMessage> messagedata;
    int running_messageindex = 1;

    [STAThreadAttribute]
    void Main(array<String^>^ args) {
        Application::EnableVisualStyles();
        Application::SetCompatibleTextRenderingDefault(false);
        simchat::MyForm form;
        Application::Run(% form);
    }

    void sendMessageAction(TextBox^ msg, TextBox^ history) {

        // This converts CLR String to std::string
        std::string new_message_str = msclr::interop::marshal_as<std::string>(msg->Text);

        sentMessage new_message;
        new_message.username = "Stinky99";
        new_message.message = new_message_str;

        // After these, the message is now saved into the data.
        messagedata.insert(messagedata.begin(), new_message);
        ++running_messageindex;

        std::string temp_string;
        int runningnum = 0;

        for (auto& n : messagedata) {
            temp_string = temp_string + n.username + " says: " + n.message + "\r\n";
            ++runningnum;
            if (runningnum == LINES_TO_PRINT) {
                break;
            }
        }

        history->Text = gcnew String(temp_string.c_str());
    }
}