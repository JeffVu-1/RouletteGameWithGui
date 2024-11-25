// Texture Loading
#define STB_IMAGE_IMPLEMENTATION

// Parent Render Window Size
#define MenuWidth 940
#define MenuHeight 500

// ImGUI Window Size
#define BackgroundWidth 640
#define BackgroundHeight 360

// MonitorSize for Calculating Application Center Pop Up
#define MonitorWidth 1920
#define MonitorHieght 1080

// IMPORTS
#include <iostream>
#include <filesystem>
#include <string>
#include <d3d11.h>
#include <tchar.h>
#include <thread>
#include <dwmapi.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/stb_image.h"
#include "Roulette Game Files/RouletteGame.h"
#include "imgui/d3dx11tex.h"

//Global Variables
int CurrentBetAmount = 0;

//Button sizes 
ImVec2 BetButtonSize(70, 70);
ImVec2 NumberButtonSize(30, 30);
ImVec2 StreetBetButtonSize(15, 15);

ImVec2 RedBlackButtonSize(60, 30);
ImVec2 OneToNineteenButtonSize(70, 30);

//Columns x Location for single number bets
constexpr int ColumnBase = 90;
constexpr int ColumnOne = ColumnBase;
constexpr int ColumnTwo = ColumnBase + 40;
constexpr int ColumnThree = ColumnBase + 82;
constexpr int ColumnFour = ColumnBase + 122;
constexpr int ColumnFive = ColumnBase + 163;
constexpr int ColumnSix = ColumnBase + 204;
constexpr int ColumnSeven = ColumnBase + 244;
constexpr int ColumnEight = ColumnBase + 285;
constexpr int ColumnNine = ColumnBase + 327;
constexpr int ColumnTen = ColumnBase + 367;
constexpr int ColumnEleven = ColumnBase + 408;
constexpr int ColumnTwelve = ColumnBase + 449;
constexpr int ColumnThirteen = ColumnBase + 490;

//Rows Y Locations for single number bets
constexpr int RowOneHeight = 185;
constexpr int RowTwoHeight = 125;
constexpr int RowThreeHeight = 65;


//StreetBet X location
constexpr int StreetOne = 98;
constexpr int StreetTwo = 138;
constexpr int StreetThree = 179;
constexpr int StreetFour = 220;
constexpr int StreetFive = 262;
constexpr int StreetSix = 303;
constexpr int StreetSeven = 344;
constexpr int StreetEight = 385;
constexpr int StreetNine = 426;
constexpr int StreetTen = 467;
constexpr int StreetEleven = 508;
constexpr int StreetTwelve = 549;

//StreetBet Y location
constexpr int StreetHeight = 220;

//Double StreetBet X Offset
constexpr int DoubleStreetBet = 20;

//SqaureBet Top and Buttom Height Y Position
constexpr int TopSquareBetHeight = 160;
constexpr int BottomSquareBetHeight = 100;

//Split Vertical Top And Bottom Height Y Position
constexpr int TopSplitVerticalBetHeight = 160;
constexpr int BottomSplitVerticalBetHeight = 100;


//Split Horizontal Top, Middle and Bottom Height Y Position
constexpr int TopSplitHorizontalBetHeight = 70;
constexpr int MiddleSplitHorizontalBetHeight = 130;
constexpr int BottomSplitHorizontalBetHeight = 190;

//Current Directory
std::wstring current_directory = std::filesystem::current_path();
std::string current_directory_string(current_directory.begin(), current_directory.end());

// Data
static ID3D11Device* g_pd3dDevice = nullptr;
static ID3D11DeviceContext* g_pd3dDeviceContext = nullptr;
static IDXGISwapChain* g_pSwapChain = nullptr;
static bool                     g_SwapChainOccluded = false;
static UINT                     g_ResizeWidth = 0, g_ResizeHeight = 0;
static ID3D11RenderTargetView* g_mainRenderTargetView = nullptr;

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
bool LoadTextureFromFile(const char* filename, ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height);

inline bool LoadImageByMemory(ID3D11Device* device, unsigned char* image, size_t image_size, ID3D11ShaderResourceView** result) {

    D3DX11_IMAGE_LOAD_INFO information;
    ID3DX11ThreadPump* thread = nullptr;

    auto hres = D3DX11CreateShaderResourceViewFromMemory(device, image, image_size, &information, thread, result, 0);
    return (hres == S_OK);
}


// Main code
int main(int, char**)
{

    // Create application window
    WNDCLASSEXW wc = { sizeof(wc), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"Roulette Table", nullptr };
    ::RegisterClassExW(&wc);

    int roundRadiusX = 15; 
    int roundRadiusY = 15;
    HRGN hRgn = CreateRoundRectRgn(0, 0, MenuWidth, MenuHeight, roundRadiusX, roundRadiusY);
    HWND hwnd = ::CreateWindowW(wc.lpszClassName, L"Roulette Table", WS_POPUP, MonitorWidth/2 - MenuWidth/2, MonitorHieght/2 - MenuHeight/2, MenuWidth, MenuHeight, nullptr, nullptr, wc.hInstance, nullptr);
    SetWindowRgn(hwnd, hRgn, TRUE);
    MARGINS margins = { -1 };
    DwmExtendFrameIntoClientArea(hwnd, &margins);

    // Initialize Direct3D
    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);
    
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.IniFilename = nullptr;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

    // Our state
    ImVec4 clear_color = ImVec4(17.0f / 255.0f, 139.0f / 255.0f, 25.0f / 255.0f, 1.0f); 

    //Initiate Game
    RouletteGame Game{150};

    //Loading Fonts
    std::string fontpath = current_directory_string + "\\Fonts\\DelaGothicOne-Regular.ttf";
    const char* fontpathCstr = fontpath.c_str();
    ImFont* font1 = io.Fonts->AddFontFromFileTTF(fontpathCstr, 19);
    ImFont* font2 = io.Fonts->AddFontFromFileTTF(fontpathCstr, 40);
    ImFont* font3 = io.Fonts->AddFontFromFileTTF(fontpathCstr, 20);
    ImFont* WelcomeFont = io.Fonts->AddFontFromFileTTF(fontpathCstr, 70);

    //Roulette Table Image Background
    int RouletteTableWidth = 0;
    int RouletteTableHeight = 0;
    ID3D11ShaderResourceView* RouletteTableTexture = NULL;

    std::string imagePath = current_directory_string + "\\Background Image\\Roulette.jpg";
    const char* imagePathCStr = imagePath.c_str();
    bool ret = LoadTextureFromFile(imagePathCStr, &RouletteTableTexture, &RouletteTableWidth, &RouletteTableHeight);

    //Roulette Chips - 5 Dollars
    int RouletteChipsFiveWidth = 0;
    int RoulettteChipsFiveHeight = 0;
    ID3D11ShaderResourceView* RoulettteChipsFiveTexture = NULL;
    std::string imagePathChipFive = current_directory_string + "\\Chips Image\\Five.png";
    const char* imagePathChipFiveCStr = imagePathChipFive.c_str();
    bool ret2 = LoadTextureFromFile(imagePathChipFiveCStr, &RoulettteChipsFiveTexture, &RouletteChipsFiveWidth, &RoulettteChipsFiveHeight);

    //Roulette Chips - 10 Dollars
    int RouletteChipsTenWidth = 0;
    int RoulettteChipsTenHeight = 0;
    ID3D11ShaderResourceView* RoulettteChipsTenTexture = NULL;
    std::string imagePathChipTen = current_directory_string + "\\Chips Image\\Ten.png";
    const char* imagePathChipTenCStr = imagePathChipTen.c_str();
    bool ret3 = LoadTextureFromFile(imagePathChipTenCStr, &RoulettteChipsTenTexture, &RouletteChipsTenWidth, &RoulettteChipsTenHeight);

    //Roulette Chips - 25 Dollars
    int RouletteChipsTwentyFiveWidth = 0;
    int RoulettteChipsTwentyFiveHeight = 0;
    ID3D11ShaderResourceView* RoulettteChipsTwentyFiveTexture = NULL;
    std::string imagePathChipTwentyFive = current_directory_string + "\\Chips Image\\TwentyFive.png";
    const char* imagePathChipTwentyFiveCStr = imagePathChipTwentyFive.c_str();
    bool ret4 = LoadTextureFromFile(imagePathChipTwentyFiveCStr, &RoulettteChipsTwentyFiveTexture, &RouletteChipsTwentyFiveWidth, &RoulettteChipsTwentyFiveHeight);

    //Roulette Chips - 50 Dollars
    int RouletteChipsFiftyWidth = 0;
    int RoulettteChipsFiftyHeight = 0;
    ID3D11ShaderResourceView* RoulettteChipsFiftyTexture = NULL;
    std::string imagePathChipFifty = current_directory_string + "\\Chips Image\\Fifty.png";
    const char* imagePathChipFiftyCStr = imagePathChipFifty.c_str();
    bool ret5 = LoadTextureFromFile(imagePathChipFiftyCStr, &RoulettteChipsFiftyTexture, &RouletteChipsFiftyWidth, &RoulettteChipsFiftyHeight);

    //Roulette Chips - 100 Dollars
    int RouletteChipsOneHundredWidth = 0;
    int RoulettteChipsOneHundredHeight = 0;
    ID3D11ShaderResourceView* RoulettteChipsOneHundredTexture = NULL;
    std::string imagePathChipOneHundred = current_directory_string + "\\Chips Image\\OneHundred.png";
    const char* imagePathChipOneHundredCStr = imagePathChipOneHundred.c_str();
    bool ret6 = LoadTextureFromFile(imagePathChipOneHundredCStr, &RoulettteChipsOneHundredTexture, &RouletteChipsOneHundredWidth, &RoulettteChipsOneHundredHeight);

    //Roulette Chips - 1000 Dollars
    int RouletteChipsOneThousandWidth = 0;
    int RoulettteChipsOneThousandHeight = 0;
    ID3D11ShaderResourceView* RoulettteChipsOneThousandTexture = NULL;
    std::string imagePathChipOneThousand = current_directory_string + "\\Chips Image\\OneThousand.png";
    const char* imagePathChipOneThousandCStr = imagePathChipOneThousand.c_str();
    bool ret7 = LoadTextureFromFile(imagePathChipOneThousandCStr, &RoulettteChipsOneThousandTexture, &RouletteChipsOneThousandWidth, &RoulettteChipsOneThousandHeight);

 
    bool WelcomeScreen = true;
    float welcomeScreenTimer = 3.0f; 
    bool SpinningScreen = false;
    float SpinningScreenTimer = 2.0f;

    // Main loop
    bool done = false;
    while (!done)
    {   

        MSG msg;
        while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done)
            break;

        if (g_SwapChainOccluded && g_pSwapChain->Present(0, DXGI_PRESENT_TEST) == DXGI_STATUS_OCCLUDED)
        {
            ::Sleep(10);
            continue;
        }
        g_SwapChainOccluded = false;


        if (g_ResizeWidth != 0 && g_ResizeHeight != 0)
        {
            CleanupRenderTarget();
            g_pSwapChain->ResizeBuffers(0, g_ResizeWidth, g_ResizeHeight, DXGI_FORMAT_UNKNOWN, 0);
            g_ResizeWidth = g_ResizeHeight = 0;
            CreateRenderTarget();
        }


        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        if (WelcomeScreen) {
            ImGui::SetNextWindowSize(ImVec2(1040, 500));
            ImGui::SetNextWindowPos(ImVec2(0, 0));
            ImGui::SetNextWindowFocus();
            ImGui::Begin("Welcome Screen", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMouseInputs | ImGuiWindowFlags_NoMove);
            ImGui::SetCursorPos(ImVec2(80, 200));
            ImGui::PushFont(WelcomeFont);
            ImGui::Text("Welcome to Table Roulette!");
            ImGui::PopFont();
            ImGui::SetCursorPos(ImVec2(320, 300));
            ImGui::PushFont(font2);
            ImGui::Text("Made By: Jeff Vu");
            ImGui::PopFont();
            ImGui::End();

            // Countdown the timer
            welcomeScreenTimer -= ImGui::GetIO().DeltaTime;
            if (welcomeScreenTimer <= 0.0f) {
                WelcomeScreen = false;
            }
        }
        

        if (!WelcomeScreen && !SpinningScreen)
        {
            //BackGround
            ImGui::SetNextWindowSize(ImVec2(638, 360));
            ImGui::SetNextWindowPos(ImVec2(0, 0));
            ImGui::Begin("Roulette!", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMouseInputs | ImGuiWindowFlags_NoMove);
            ImGui::GetWindowDrawList()->AddImage(RouletteTableTexture, ImVec2(0, 0), ImVec2(BackgroundWidth, BackgroundHeight));
            ImGui::End();

            //Chat Log
            SpinNumbers PreviousSpinNumbers = Game.GetPreviousSpinNumbers();

            std::string PreviousNumberColor = Game.GetNumberColor(PreviousSpinNumbers.previousSpinNumber);
            std::string PreviousNumberColorTwo = Game.GetNumberColor(PreviousSpinNumbers.previousPreviousSpinNumber);
            std::string PreviousNumberColorThree = Game.GetNumberColor(PreviousSpinNumbers.previousPreviousPreviousSpinNumber);
            std::string PreviousNumberColorFour = Game.GetNumberColor(PreviousSpinNumbers.previousPreviousPreviousPreviousSpinNumber);

            std::string PreviousNumber = "Previous Number was: " + std::to_string(PreviousSpinNumbers.previousSpinNumber) + " " + PreviousNumberColor;
            std::string PreviousNumberTwo = "Previous Number was: " + std::to_string(PreviousSpinNumbers.previousPreviousSpinNumber) + " " + PreviousNumberColorTwo;
            std::string PreviousNumberThree = "Previous Number was: " + std::to_string(PreviousSpinNumbers.previousPreviousPreviousSpinNumber) + " " + PreviousNumberColorThree;
            std::string PreviousNumberFour = "Previous Number was: " + std::to_string(PreviousSpinNumbers.previousPreviousPreviousPreviousSpinNumber) + " " + PreviousNumberColorFour;

            const char* PreviousNumberCstr = PreviousNumber.c_str();
            const char* PreviousNumberCstrTwo = PreviousNumberTwo.c_str();
            const char* PreviousNumberCstrThree = PreviousNumberThree.c_str();
            const char* PreviousNumberCstrFour = PreviousNumberFour.c_str();

            ImGui::SetNextWindowSize(ImVec2(400, 360));
            ImGui::SetNextWindowPos(ImVec2(638, 0));
            ImGui::Begin("Chat Log", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMouseInputs | ImGuiWindowFlags_NoMove);
            ImGui::PushFont(font3);
            ImGui::Text("Information");
            if (Game.GetShowPreviousFour()) { ImGui::Text(PreviousNumberCstrFour); };
            if (Game.GetShowPreviousThree()) { ImGui::Text(PreviousNumberCstrThree); };
            if (Game.GetShowPreviousTwo()) { ImGui::Text(PreviousNumberCstrTwo); };
            if (Game.GetShowPreviousOne()) { ImGui::Text(PreviousNumberCstr); };
            ImGui::PopFont();

            ImGui::End();

            //ForeGround
            ImGui::SetNextWindowSize(ImVec2(MenuWidth, MenuHeight));
            ImGui::SetNextWindowPos(ImVec2(0, 0));

            ImGui::Begin("BUTTONS", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove);
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.0f, 0.0f, 0.40f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1.0f, 1.0f, 1.0f, 0.20f));
            ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 50.0f);

            //User Information
            ImGui::SetCursorPos(ImVec2(5, 20));
            ImGui::Text("Total Bets: $%d", Game.GetBetAmount());

            ImGui::SetCursorPos(ImVec2(205, 20));
            ImGui::Text("Balance: $%d", Game.GetCurrentBalance());

            ImGui::SetCursorPos(ImVec2(405, 20));
            ImGui::Text("Selected Chip Amount: $%d", CurrentBetAmount);


            // Set cursor positions and draw buttons
            ImGui::SetCursorPos(ImVec2(30, 380)); // 5 Dollar Bet
            if (ImGui::ImageButton("$5", RoulettteChipsFiveTexture, BetButtonSize))
            {
                CurrentBetAmount = 5;
            };

            ImGui::SetCursorPos(ImVec2(100, 380)); // 10 Dollar Bet
            if (ImGui::ImageButton("$10", RoulettteChipsTenTexture, BetButtonSize))
            {
                CurrentBetAmount = 10;
            };

            ImGui::SetCursorPos(ImVec2(170, 380)); // 20 Dollar Bet 
            if (ImGui::ImageButton("$25", RoulettteChipsTwentyFiveTexture, BetButtonSize))
            {
                CurrentBetAmount = 25;
            };

            ImGui::SetCursorPos(ImVec2(240, 380)); // 50 Dollar Bet
            if (ImGui::ImageButton("$50", RoulettteChipsFiftyTexture, BetButtonSize))
            {
                CurrentBetAmount = 50;
            };

            ImGui::SetCursorPos(ImVec2(310, 380)); // 100 Dollar Bet
            if (ImGui::ImageButton("$100", RoulettteChipsOneHundredTexture, BetButtonSize))
            {
                CurrentBetAmount = 100;
            };

            ImGui::SetCursorPos(ImVec2(380, 380)); // 1000 Dollar Bet
            if (ImGui::ImageButton("$1000", RoulettteChipsOneThousandTexture, BetButtonSize))
            {
                CurrentBetAmount = 1000;
            };

            ImGui::PopStyleColor(4);
            ImGui::PopStyleVar();

            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 1.0f, 1.0f, 0.1f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 1.0f, 1.0f, 0.40f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1.0f, 1.0f, 1.0f, 0.20f));
            ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 10.0f);

            ImGui::SetCursorPos(ImVec2(470, 370)); // Clear Bets
            ImGui::PushFont(font2);
            if (ImGui::Button("Clear", ImVec2(130, 40)))
            {
                Game.ClearAllBets();
            };

            ImGui::SetCursorPos(ImVec2(470, 430)); // SPIN WHEEL

            if (ImGui::Button("Spin!", ImVec2(130, 40)) && Game.GetBetAmount() > 0)
            {          
                    SpinningScreen = true;     
            };

            ImGui::PopStyleColor(4);
            ImGui::PopStyleVar();
            ImGui::PopFont();

            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 1.0f, 1.0f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 1.0f, 1.0f, 0.40f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1.0f, 1.0f, 1.0f, 0.20f));
            ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.0f);


            // 1st12 | 2nd12 | 3rd12
            ImGui::SetCursorPos(ImVec2(140, 232)); // Button 1st12 Location
            if (ImGui::Button("##1st12", ImVec2(RedBlackButtonSize))) { Game.AddToBetFirstTwelve(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(300, 232)); // Button 2nd12 Location
            if (ImGui::Button("##2nd12", ImVec2(RedBlackButtonSize))) { Game.AddToBetSecondTwelve(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(465, 232)); // Button 3rd12 Location
            if (ImGui::Button("##3rd12", ImVec2(RedBlackButtonSize))) { Game.AddToBetThirdTwelve(CurrentBetAmount); };


            // 1 to 19 | 19 to 36
            ImGui::SetCursorPos(ImVec2(90, 275)); // Button 1 to 18 Location
            if (ImGui::Button("##1 to 18", ImVec2(OneToNineteenButtonSize))) { Game.AddToBetOneToEighteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(500, 275)); // Button 19 to 36 Location
            if (ImGui::Button("##19 to 36", ImVec2(OneToNineteenButtonSize))) { Game.AddToBetNineteenToThirtySix(CurrentBetAmount); };


            // ODD | EVEN
            ImGui::SetCursorPos(ImVec2(175, 275)); // Button EVEN Location
            if (ImGui::Button("##EVEN", ImVec2(RedBlackButtonSize))) { Game.AddToBetRed(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(420, 275)); // Button ODD Location
            if (ImGui::Button("##ODD", ImVec2(RedBlackButtonSize))) { Game.AddToBetBlack(CurrentBetAmount); };


            // RED |  BLACK
            ImGui::SetCursorPos(ImVec2(255, 275)); // Button RED Location
            if (ImGui::Button("##RED", ImVec2(RedBlackButtonSize))) { Game.AddToBetRed(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(340, 275)); // Button BLACK Location
            if (ImGui::Button("##BLACK", ImVec2(RedBlackButtonSize))) { Game.AddToBetBlack(CurrentBetAmount); }


            // Number Bets
            ImGui::SetCursorPos(ImVec2(39, RowTwoHeight)); // Button 0 Location
            if (ImGui::Button("##ZERO", ImVec2(NumberButtonSize))) { Game.AddToBetNumberZero(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(ColumnOne, RowOneHeight)); // Button 1 Location
            if (ImGui::Button("##ONE", ImVec2(NumberButtonSize))) { Game.AddToBetNumberOne(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnOne, RowTwoHeight)); // Button 2 Location
            if (ImGui::Button("##TWO", ImVec2(NumberButtonSize))) { Game.AddToBetNumberTwo(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnOne, RowThreeHeight)); // Button 3 Location
            if (ImGui::Button("##THREE", ImVec2(NumberButtonSize))) { Game.AddToBetNumberThree(CurrentBetAmount); };



            ImGui::SetCursorPos(ImVec2(ColumnTwo, RowOneHeight)); // Button 4 Location
            if (ImGui::Button("##FOUR", ImVec2(NumberButtonSize))) { Game.AddToBetNumberFour(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnTwo, RowTwoHeight)); // Button 5 Location
            if (ImGui::Button("##FIVE", ImVec2(NumberButtonSize))) { Game.AddToBetNumberFive(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnTwo, RowThreeHeight)); // Button 6 Location
            if (ImGui::Button("##SIX", ImVec2(NumberButtonSize))) { Game.AddToBetNumberSix(CurrentBetAmount); };



            ImGui::SetCursorPos(ImVec2(ColumnThree, RowOneHeight)); // Button 7 Location
            if (ImGui::Button("##SEVEN", ImVec2(NumberButtonSize))) { Game.AddToBetNumberSeven(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnThree, RowTwoHeight)); // Button 8 Location
            if (ImGui::Button("##EIGHT", ImVec2(NumberButtonSize))) { Game.AddToBetNumberEight(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnThree, RowThreeHeight)); // Button 9 Location
            if (ImGui::Button("##NINE", ImVec2(NumberButtonSize))) { Game.AddToBetNumberNine(CurrentBetAmount); };



            ImGui::SetCursorPos(ImVec2(ColumnFour, RowOneHeight)); // Button 10 Location
            if (ImGui::Button("##TEN", ImVec2(NumberButtonSize))) { Game.AddToBetNumberTen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnFour, RowTwoHeight)); // Button 11 Location
            if (ImGui::Button("##ELEVEN", ImVec2(NumberButtonSize))) { Game.AddToBetNumberEleven(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnFour, RowThreeHeight)); // Button 12 Location
            if (ImGui::Button("##TWELVE", ImVec2(NumberButtonSize))) { Game.AddToBetNumberTwelve(CurrentBetAmount); };



            ImGui::SetCursorPos(ImVec2(ColumnFive, RowOneHeight)); // Button 13 Location
            if (ImGui::Button("##THIRTEEN", ImVec2(NumberButtonSize))) { Game.AddToBetNumberThirteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnFive, RowTwoHeight)); // Button 14 Location
            if (ImGui::Button("##FOURTEEN", ImVec2(NumberButtonSize))) { Game.AddToBetNumberFourteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnFive, RowThreeHeight)); // Button 15 Location
            if (ImGui::Button("##FIFTEEN", ImVec2(NumberButtonSize))) { Game.AddToBetNumberFifteen(CurrentBetAmount); };



            ImGui::SetCursorPos(ImVec2(ColumnSix, RowOneHeight)); // Button 16 Location
            if (ImGui::Button("##SIXTEEN", ImVec2(NumberButtonSize))) { Game.AddToBetNumberSixteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnSix, RowTwoHeight)); // Button 17 Location
            if (ImGui::Button("##SEVENTEEN", ImVec2(NumberButtonSize))) { Game.AddToBetNumberSeventeen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnSix, RowThreeHeight)); // Button 18 Location
            if (ImGui::Button("##EIGHTEEN", ImVec2(NumberButtonSize))) { Game.AddToBetNumberEighteen(CurrentBetAmount); };



            ImGui::SetCursorPos(ImVec2(ColumnSeven, RowOneHeight)); // Button 19 Location
            if (ImGui::Button("##NINETEEN", ImVec2(NumberButtonSize))) { Game.AddToBetNumberNineteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnSeven, RowTwoHeight)); // Button 20 Location
            if (ImGui::Button("##TWENTY", ImVec2(NumberButtonSize))) { Game.AddToBetNumberTwenty(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnSeven, RowThreeHeight)); // Button 21 Location
            if (ImGui::Button("##TWENTY-ONE", ImVec2(NumberButtonSize))) { Game.AddToBetNumberTwentyOne(CurrentBetAmount); };



            ImGui::SetCursorPos(ImVec2(ColumnEight, RowOneHeight)); // Button 22 Location
            if (ImGui::Button("##TWENTY-TWO", ImVec2(NumberButtonSize))) { Game.AddToBetNumberTwentyTwo(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnEight, RowTwoHeight)); // Button 23 Location
            if (ImGui::Button("##TWENTY-THREE", ImVec2(NumberButtonSize))) { Game.AddToBetNumberTwentyThree(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnEight, RowThreeHeight)); // Button 24 Location
            if (ImGui::Button("##TWENTY-FOUR", ImVec2(NumberButtonSize))) { Game.AddToBetNumberTwentyFour(CurrentBetAmount); };



            ImGui::SetCursorPos(ImVec2(ColumnNine, RowOneHeight)); // Button 25 Location
            if (ImGui::Button("##TWENTY-FIVE", ImVec2(NumberButtonSize))) { Game.AddToBetNumberTwentyFive(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnNine, RowTwoHeight)); // Button 26 Location
            if (ImGui::Button("##TWENTY-SIX", ImVec2(NumberButtonSize))) { Game.AddToBetNumberTwentySix(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnNine, RowThreeHeight)); // Button 27 Location
            if (ImGui::Button("##TWENTY-SEVEN", ImVec2(NumberButtonSize))) { Game.AddToBetNumberTwentySeven(CurrentBetAmount); };



            ImGui::SetCursorPos(ImVec2(ColumnTen, RowOneHeight)); // Button 28 Location
            if (ImGui::Button("##TWENTY-EIGHT", ImVec2(NumberButtonSize))) { Game.AddToBetNumberTwentyEight(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnTen, RowTwoHeight)); // Button 29 Location
            if (ImGui::Button("##TWENTY-NINE", ImVec2(NumberButtonSize))) { Game.AddToBetNumberTwentyNine(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnTen, RowThreeHeight)); // Button 30 Location
            if (ImGui::Button("##THIRTY", ImVec2(NumberButtonSize))) { Game.AddToBetNumberThirty(CurrentBetAmount); };



            ImGui::SetCursorPos(ImVec2(ColumnEleven, RowOneHeight)); // Button 31 Location
            if (ImGui::Button("##THIRTY-ONE", ImVec2(NumberButtonSize))) { Game.AddToBetNumberThirtyOne(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnEleven, RowTwoHeight)); // Button 32 Location
            if (ImGui::Button("##THIRTY-TWO", ImVec2(NumberButtonSize))) { Game.AddToBetNumberThirtyTwo(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnEleven, RowThreeHeight)); // Button 33 Location
            if (ImGui::Button("##THIRTY-THREE", ImVec2(NumberButtonSize))) { Game.AddToBetNumberThirtyThree(CurrentBetAmount); };



            ImGui::SetCursorPos(ImVec2(ColumnTwelve, RowOneHeight)); // Button 34 Location
            if (ImGui::Button("##THIRTY-FOUR", ImVec2(NumberButtonSize))) { Game.AddToBetNumberThirtyFour(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnTwelve, RowTwoHeight)); // Button 35 Location
            if (ImGui::Button("##THIRTY-FIVE", ImVec2(NumberButtonSize))) { Game.AddToBetNumberThirtyFive(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnTwelve, RowThreeHeight)); // Button 36 Location
            if (ImGui::Button("##THIRTY-SIX", ImVec2(NumberButtonSize))) { Game.AddToBetNumberThirtySix(CurrentBetAmount); };



            ImGui::SetCursorPos(ImVec2(ColumnThirteen, RowOneHeight));   // Button ColumnOne - 1 Location
            if (ImGui::Button("##Column 1", ImVec2(NumberButtonSize))) { Game.AddToBetFirstColumn(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnThirteen, RowTwoHeight));   // Button ColumnTwo - 2 Location
            if (ImGui::Button("##Column 2", ImVec2(NumberButtonSize))) { Game.AddToBetSecondColumn(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(ColumnThirteen, RowThreeHeight)); // Button ColumnThree - 3 Location
            if (ImGui::Button("##Column 3", ImVec2(NumberButtonSize))) { Game.AddToBetThirdColumn(CurrentBetAmount); };

            ImGui::PopStyleColor(3);
            ImGui::PopStyleVar();

            //Added color for debugging
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(66.0f / 255.0f, 135.0f / 255.0f, 245.0f / 255.0f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 1.0f, 1.0f, 0.40f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1.0f, 1.0f, 1.0f, 0.20f));
            ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.0f);

            //Street Bets color blue
            ImGui::SetCursorPos(ImVec2(StreetOne, StreetHeight));
            if (ImGui::Button("##Street 1 (1 2 3)", ImVec2(StreetBetButtonSize))) { Game.AddToBetStreetOne(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetTwo, StreetHeight));
            if (ImGui::Button("##Street 2 (4 5 6)", ImVec2(StreetBetButtonSize))) { Game.AddToBetStreetTwo(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetThree, StreetHeight));
            if (ImGui::Button("##Street 3 (7 8 9)", ImVec2(StreetBetButtonSize))) { Game.AddToBetStreetThree(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetFour, StreetHeight));
            if (ImGui::Button("##Street 4 (12 11 12)", ImVec2(StreetBetButtonSize))) { Game.AddToBetStreetFour(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetFive, StreetHeight));
            if (ImGui::Button("##Street 5 (13 14 15)", ImVec2(StreetBetButtonSize))) { Game.AddToBetStreetFive(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetSix, StreetHeight));
            if (ImGui::Button("##Street 6 (16 17 18)", ImVec2(StreetBetButtonSize))) { Game.AddToBetStreetSix(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetSeven, StreetHeight));
            if (ImGui::Button("##Street 7 (19 20 21)", ImVec2(StreetBetButtonSize))) { Game.AddToBetStreetSeven(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetEight, StreetHeight));
            if (ImGui::Button("##Street 8 (22 23 24)", ImVec2(StreetBetButtonSize))) { Game.AddToBetStreetEight(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetNine, StreetHeight));
            if (ImGui::Button("##Street 9 (25 26 27)", ImVec2(StreetBetButtonSize))) { Game.AddToBetStreetNine(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetTen, StreetHeight));
            if (ImGui::Button("##Street 10 (28 29 30)", ImVec2(StreetBetButtonSize))) { Game.AddToBetStreetTen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetEleven, StreetHeight));
            if (ImGui::Button("##Street 11 (31 32 33)", ImVec2(StreetBetButtonSize))) { Game.AddToBetStreetEleven(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetTwelve, StreetHeight));
            if (ImGui::Button("##Street 12 (34 35 36)", ImVec2(StreetBetButtonSize))) { Game.AddToBetStreetTwelve(CurrentBetAmount); };


            ImGui::PopStyleColor(3);
            ImGui::PopStyleVar();


            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(219.0f / 255.0f, 118.0f / 255.0f, 46.0f / 255.0f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 1.0f, 1.0f, 0.40f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1.0f, 1.0f, 1.0f, 0.20f));
            ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.0f);

            //Single Street Bets European color Orange
            ImGui::SetCursorPos(ImVec2(StreetOne - DoubleStreetBet, StreetHeight - 60));
            if (ImGui::Button("##Street 0 and 1/2 (0 1 2)", ImVec2(StreetBetButtonSize))) { Game.AddToBetStreetZeroOneTwo(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetOne - DoubleStreetBet, StreetHeight - 120));
            if (ImGui::Button("##Street 0 and 2/2 (0 2 3)", ImVec2(StreetBetButtonSize))) { Game.AddToBetStreetZeroTwoThree(CurrentBetAmount); };


            //Double Street Bets color ORANGE
            ImGui::SetCursorPos(ImVec2(StreetOne - DoubleStreetBet, StreetHeight));
            if (ImGui::Button("##Street 0 and 1 (0 1 2 3)", ImVec2(StreetBetButtonSize))) { Game.AddToBetDoubleStreetZeroOneTwoThree(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetOne + DoubleStreetBet, StreetHeight));
            if (ImGui::Button("##Street 1 and 2 (1 2 3 4 5 6)", ImVec2(StreetBetButtonSize))) { Game.AddToBetDoubleStreetOneTwo(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetTwo + DoubleStreetBet, StreetHeight));
            if (ImGui::Button("##Street 2 and 3 (4 5 6 7 8 9)", ImVec2(StreetBetButtonSize))) { Game.AddToBetDoubleStreetTwoThree(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetThree + DoubleStreetBet, StreetHeight));
            if (ImGui::Button("##Street 3 and 4 (7 8 9 10 11 12)", ImVec2(StreetBetButtonSize))) { Game.AddToBetDoubleStreetThreeFour(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetFour + DoubleStreetBet, StreetHeight));
            if (ImGui::Button("##Street 4 and 5 (10 11 12 13 14 15)", ImVec2(StreetBetButtonSize))) { Game.AddToBetDoubleStreetFourFive(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetFive + DoubleStreetBet, StreetHeight));
            if (ImGui::Button("##Street 5 and 6 (13 14 15 16 17 18)", ImVec2(StreetBetButtonSize))) { Game.AddToBetDoubleStreetFiveSix(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetSix + DoubleStreetBet, StreetHeight));
            if (ImGui::Button("##Street 6 and 7 (16 17 18 19 20 21)", ImVec2(StreetBetButtonSize))) { Game.AddToBetDoubleStreetSixSeven(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetSeven + DoubleStreetBet, StreetHeight));
            if (ImGui::Button("##Street 7 and 8 (19 20 21 22 23 24)", ImVec2(StreetBetButtonSize))) { Game.AddToBetDoubleStreetSevenEight(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetEight + DoubleStreetBet, StreetHeight));
            if (ImGui::Button("##Street 8 and 9 (22 23 24 25 26 27)", ImVec2(StreetBetButtonSize))) { Game.AddToBetDoubleStreetEightNine(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetNine + DoubleStreetBet, StreetHeight));
            if (ImGui::Button("##Street 9 and 10 (25 26 27 28 29 30)", ImVec2(StreetBetButtonSize))) { Game.AddToBetDoubleStreetNineTen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetTen + DoubleStreetBet, StreetHeight));
            if (ImGui::Button("##Street 10 and 11 (28 29 30 31 32 33)", ImVec2(StreetBetButtonSize))) { Game.AddToBetDoubleStreetTenEleven(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetEleven + DoubleStreetBet, StreetHeight));
            if (ImGui::Button("##Street 11 and 12 (31 32 33 34 35 36)", ImVec2(StreetBetButtonSize))) { Game.AddToBetDoubleStreetElevenTwelve(CurrentBetAmount); };

            ImGui::PopStyleColor(3);
            ImGui::PopStyleVar();


            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(235.0f / 255.0f, 210.0f / 255.0f, 52.0f / 255.0f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 1.0f, 1.0f, 0.40f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1.0f, 1.0f, 1.0f, 0.20f));
            ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.0f);


            //Square Bets 22 combintations color YELLOW
            ImGui::SetCursorPos(ImVec2(StreetOne + DoubleStreetBet, BottomSquareBetHeight));
            if (ImGui::Button("##Street Square 1 (1,2,4,5)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareOne(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetOne + DoubleStreetBet, TopSquareBetHeight));
            if (ImGui::Button("##Street Square 2 (2,3,5,6)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareTwo(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetTwo + DoubleStreetBet, BottomSquareBetHeight));
            if (ImGui::Button("##Street Square 3 (4,5,7,8)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareThree(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetTwo + DoubleStreetBet, TopSquareBetHeight));
            if (ImGui::Button("##Street Square 4 (5,6,8,9)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareFour(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetThree + DoubleStreetBet, BottomSquareBetHeight));
            if (ImGui::Button("##Street Square 5 (7,8,10,11)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareFive(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetThree + DoubleStreetBet, TopSquareBetHeight));
            if (ImGui::Button("##Street Square 6 (8,9,11,12)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareSix(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetFour + DoubleStreetBet, BottomSquareBetHeight));
            if (ImGui::Button("##Street Square 7 (10,11,13,14)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareSeven(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetFour + DoubleStreetBet, TopSquareBetHeight));
            if (ImGui::Button("##Street Square 8 (11,12,14,15)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareEight(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetFive + DoubleStreetBet, BottomSquareBetHeight));
            if (ImGui::Button("##Street Square 9 (13,14,16,17)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareNine(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetFive + DoubleStreetBet, TopSquareBetHeight));
            if (ImGui::Button("##Street Square 10 (14,15,17,18)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareTen(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetSix + DoubleStreetBet, BottomSquareBetHeight));
            if (ImGui::Button("##Street Square 11 (16,17,19,20)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareEleven(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetSix + DoubleStreetBet, TopSquareBetHeight));
            if (ImGui::Button("##Street Square 12 (17,18,20,21)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareTwelve(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetSeven + DoubleStreetBet, BottomSquareBetHeight));
            if (ImGui::Button("##Street Square 13 (19,20,22,23)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareThirteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetSeven + DoubleStreetBet, TopSquareBetHeight));
            if (ImGui::Button("##Street Square 14 (20,21,23,24)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareFourteen(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetEight + DoubleStreetBet, BottomSquareBetHeight));
            if (ImGui::Button("##Street Square 15 (22,23,25,26)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareFifteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetEight + DoubleStreetBet, TopSquareBetHeight));
            if (ImGui::Button("##Street Square 16 (23,24,26,27)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareSixteen(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetNine + DoubleStreetBet, BottomSquareBetHeight));
            if (ImGui::Button("##Street Square 17 (25,26,28,29)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareSeventeen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetNine + DoubleStreetBet, TopSquareBetHeight));
            if (ImGui::Button("##Street Square 18 (26,27,29,30)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareEighteen(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetTen + DoubleStreetBet, BottomSquareBetHeight));
            if (ImGui::Button("##Street Square 19 (28,29,31,32)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareNineteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetTen + DoubleStreetBet, TopSquareBetHeight));
            if (ImGui::Button("##Street Square 20 (29,30,32,33)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareTwenty(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetEleven + DoubleStreetBet, BottomSquareBetHeight));
            if (ImGui::Button("##Street Square 21 (31,32,34,35)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareTwentyOne(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetEleven + DoubleStreetBet, TopSquareBetHeight));
            if (ImGui::Button("##Street Square 22 (32,33,35,36)", ImVec2(StreetBetButtonSize))) { Game.AddToBetSquareTwentyTwo(CurrentBetAmount); };


            ImGui::PopStyleColor(3);
            ImGui::PopStyleVar();

            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(66.0f / 255.0f, 245.0f / 255.0f, 132.0f / 255.0f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 1.0f, 1.0f, 0.40f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1.0f, 1.0f, 1.0f, 0.20f));
            ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.0f);

            //Split Vertical Two Number Bets Color Green
            ImGui::SetCursorPos(ImVec2(StreetOne, BottomSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 1 (1,2)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitOne(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetOne, TopSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 2 (2,3)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitTwo(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetTwo, BottomSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 3 (4,5)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitThree(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetTwo, TopSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 4 (5,6)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitFour(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetThree, BottomSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 5 (7,8)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitFive(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetThree, TopSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 6 (8,9)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitSix(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetFour, BottomSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 7 (10,11)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitSeven(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetFour, TopSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 8 (11,12)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitEight(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetFive, BottomSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 9 (13,14)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitNine(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetFive, TopSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 10 (14,15)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitTen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetSix, BottomSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 11 (16,17)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitEleven(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetSix, TopSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 12 (17,18)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitTwelve(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetSeven, BottomSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 13 (19,20)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitThirteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetSeven, TopSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 14 (20,21)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitFourteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetEight, BottomSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 15 (22,23)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitFifteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetEight, TopSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 16 (23,24)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitSixteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetNine, BottomSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 17 (25,26)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitSeventeen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetNine, TopSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 18 (26,27)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitEighteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetTen, BottomSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 19 (28,29)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitNineteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetTen, TopSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 20 (29,30)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitTwenty(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetEleven, BottomSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 21 (31,32)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitTwentyone(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetEleven, TopSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 22 (32,33)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitTwentytwo(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetTwelve, BottomSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 23 (34,35)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitTwentythree(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetTwelve, TopSplitVerticalBetHeight));
            if (ImGui::Button("##Split Vertical Bet 24 (35,36)", ImVec2(StreetBetButtonSize))) { Game.AddToBetVerticalSplitTwentyfour(CurrentBetAmount); };

            ImGui::PopStyleColor(3);
            ImGui::PopStyleVar();

            //Color Pink 237, 130, 155
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(237.0f / 255.0f, 130.0f / 255.0f, 155.0f / 255.0f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 1.0f, 1.0f, 0.40f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1.0f, 1.0f, 1.0f, 0.20f));
            ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.0f);

            ImGui::SetCursorPos(ImVec2(StreetOne + DoubleStreetBet, BottomSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 1 (1,4)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitOne(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetOne + DoubleStreetBet, MiddleSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 2 (2,5)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitTwo(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetOne + DoubleStreetBet, TopSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 3 (3,6)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitThree(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetTwo + DoubleStreetBet, BottomSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 4 (4,7)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitFour(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetTwo + DoubleStreetBet, MiddleSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 5 (5,8)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitFive(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetTwo + DoubleStreetBet, TopSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 6 (6,9)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitSix(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetThree + DoubleStreetBet, BottomSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 7 (7,10)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitSeven(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetThree + DoubleStreetBet, MiddleSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 8 (8,11)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitEight(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetThree + DoubleStreetBet, TopSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 9 (9,12)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitNine(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetFour + DoubleStreetBet, BottomSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 10 (10,13)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitTen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetFour + DoubleStreetBet, MiddleSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 11 (11,14)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitEleven(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetFour + DoubleStreetBet, TopSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 12 (12,15)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitTwelve(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetFive + DoubleStreetBet, BottomSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 13 (13,16)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitThirteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetFive + DoubleStreetBet, MiddleSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 14 (14,17)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitFourteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetFive + DoubleStreetBet, TopSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 15 (15,18)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitFifteen(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetSix + DoubleStreetBet, BottomSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 16 (16,19)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitSixteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetSix + DoubleStreetBet, MiddleSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 17 (17,20)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitSeventeen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetSix + DoubleStreetBet, TopSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 18 (18,21)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitEighteen(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetSeven + DoubleStreetBet, BottomSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 19 (19,22)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitNineteen(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetSeven + DoubleStreetBet, MiddleSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 20 (20,23)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitTwenty(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetSeven + DoubleStreetBet, TopSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 21 (21,24)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitTwentyOne(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetEight + DoubleStreetBet, BottomSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 22 (22,25)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitTwentyTwo(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetEight + DoubleStreetBet, MiddleSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 23 (23,26)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitTwentyThree(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetEight + DoubleStreetBet, TopSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 24 (24,27)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitTwentyFour(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetNine + DoubleStreetBet, BottomSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 25 (25,28)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitTwentyFive(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetNine + DoubleStreetBet, MiddleSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 26 (26,29)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitTwentySix(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetNine + DoubleStreetBet, TopSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 27 (27,30)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitTwentySeven(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetTen + DoubleStreetBet, BottomSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 28 (28,31)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitTwentyEight(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetTen + DoubleStreetBet, MiddleSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 29 (29,32)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitTwentyNine(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetTen + DoubleStreetBet, TopSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 30 (30,33)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitThirty(CurrentBetAmount); };


            ImGui::SetCursorPos(ImVec2(StreetEleven + DoubleStreetBet, BottomSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 31 (31,34)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitThirtyOne(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetEleven + DoubleStreetBet, MiddleSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 32 (32,35)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitThirtyTwo(CurrentBetAmount); };

            ImGui::SetCursorPos(ImVec2(StreetEleven + DoubleStreetBet, TopSplitHorizontalBetHeight));
            if (ImGui::Button("##Split Horizontal Bet 33 (33,36)", ImVec2(StreetBetButtonSize))) { Game.AddToBetHorizontalSplitThirtyThree(CurrentBetAmount); };


            ImGui::PopStyleColor(3);
            ImGui::PopStyleVar();
            ImGui::End();
        }


        if (SpinningScreen) {
            ImGui::SetNextWindowSize(ImVec2(1040, 500));
            ImGui::SetNextWindowPos(ImVec2(0, 0));
            ImGui::SetNextWindowFocus();
            ImGui::Begin("Welcome Screen", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMouseInputs | ImGuiWindowFlags_NoMove);
            ImGui::SetCursorPos(ImVec2(120, 200));
            ImGui::PushFont(WelcomeFont);
            ImGui::Text("Spinning Roulette!");
            ImGui::PopFont();
            ImGui::End();

            // Countdown the timer
            SpinningScreenTimer -= ImGui::GetIO().DeltaTime;
            if (SpinningScreenTimer <= 0.0f) {
                Game.GenerateRandomNumber();
                Game.StartRound();
                // add to update screen what it lands on
                SpinningScreen = false;
                SpinningScreenTimer = 2.0f;

            }
        }

        // Rendering
        ImGui::Render();
        const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
        g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, nullptr);
        g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, clear_color_with_alpha);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

        // Present
        HRESULT hr = g_pSwapChain->Present(1, 0);  
        g_SwapChainOccluded = (hr == DXGI_STATUS_OCCLUDED);
    }

    // Cleanup
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);

    return 0;
}


// Helper functions
bool CreateDeviceD3D(HWND hWnd)
{
    // Setup swap chain
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 2;
    sd.BufferDesc.Width = 0;
    sd.BufferDesc.Height = 0;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    UINT createDeviceFlags = 0;
    //createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
    D3D_FEATURE_LEVEL featureLevel;
    const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
    HRESULT res = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext);
    if (res == DXGI_ERROR_UNSUPPORTED)
        res = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_WARP, nullptr, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext);
    if (res != S_OK)
        return false;

    CreateRenderTarget();
    return true;
}

void CleanupDeviceD3D()
{
    CleanupRenderTarget();
    if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = nullptr; }
    if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = nullptr; }
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = nullptr; }
}

void CreateRenderTarget()
{
    ID3D11Texture2D* pBackBuffer;
    g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
    g_pd3dDevice->CreateRenderTargetView(pBackBuffer, nullptr, &g_mainRenderTargetView);
    pBackBuffer->Release();
}

void CleanupRenderTarget()
{
    if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = nullptr; }
}

bool LoadTextureFromFile(const char* filename, ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height)
{
    // Load from disk into a raw RGBA buffer
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;

    // Create texture
    D3D11_TEXTURE2D_DESC desc;
    ZeroMemory(&desc, sizeof(desc));
    desc.Width = image_width;
    desc.Height = image_height;
    desc.MipLevels = 1;
    desc.ArraySize = 1;
    desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.SampleDesc.Count = 1;
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    desc.CPUAccessFlags = 0;

    ID3D11Texture2D* pTexture = NULL;
    D3D11_SUBRESOURCE_DATA subResource;
    subResource.pSysMem = image_data;
    subResource.SysMemPitch = desc.Width * 4;
    subResource.SysMemSlicePitch = 0;
    g_pd3dDevice->CreateTexture2D(&desc, &subResource, &pTexture);

    // Create texture view
    D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
    ZeroMemory(&srvDesc, sizeof(srvDesc));
    srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
    srvDesc.Texture2D.MipLevels = desc.MipLevels;
    srvDesc.Texture2D.MostDetailedMip = 0;
    g_pd3dDevice->CreateShaderResourceView(pTexture, &srvDesc, out_srv);
    pTexture->Release();

    *out_width = image_width;
    *out_height = image_height;
    stbi_image_free(image_data);

    return true;
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static bool isDragging = false;
    static POINT lastLocation;

    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (wParam == SIZE_MINIMIZED)
            return 0;
        g_ResizeWidth = (UINT)LOWORD(lParam); // Queue resize
        g_ResizeHeight = (UINT)HIWORD(lParam);
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    case WM_LBUTTONDOWN:
        // Check if the mouse click is within the top 100 pixels
        POINT clickPos;
        GetCursorPos(&clickPos);
        ScreenToClient(hWnd, &clickPos);
        if (clickPos.y <= 100) {
            isDragging = true;
            GetCursorPos(&lastLocation);
            ScreenToClient(hWnd, &lastLocation);
        }
        break;

    case WM_LBUTTONUP:
        isDragging = false;
        break;

    case WM_MOUSEMOVE:
        if (isDragging)
        {
            POINT currentPos;
            GetCursorPos(&currentPos);
            int dx = currentPos.x - lastLocation.x;
            int dy = currentPos.y - lastLocation.y;
            SetWindowPos(hWnd, NULL, dx, dy, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        }
        break;
    }
    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}