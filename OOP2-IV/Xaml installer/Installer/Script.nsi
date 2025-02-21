; Пример скрипта установки на NSIS с выбором места установки

; Установка имени и версии программы
!define VERSION "1.0.0.0" ; Установите версию вашего приложения
!define COMPANY_NAME "IVT22 Nazar Stich"
!define PRODUCT_NAME "Time Calculator"
VIProductVersion ${VERSION}
VIAddVersionKey ProductName "${PRODUCT_NAME}"
VIAddVersionKey CompanyName "${COMPANY_NAME}"
VIAddVersionKey ProductVersion "${VERSION}"

Name "${PRODUCT_NAME}"
OutFile "Setup.exe"

; Определение файлов для установки
Section "Приложение"
    ; Запросить у пользователя место установки
    SetOutPath "$INSTDIR"

    ; Копирование исполняемого файла в установочную папку
    File "X:\Programming II\OOP2-IV\Xaml installer\TimeTimeTime\bin\Debug\TimeTimeTime.exe"

SectionEnd

; Завершение установки
Section "Готово"
    MessageBox MB_OK "Установка завершена успешно!"
SectionEnd

; Запросить у пользователя место установки
Function .onInit
    StrCpy $INSTDIR "C:\Program Files\${COMPANY_NAME}\${PRODUCT_NAME}"
FunctionEnd

; Запросить у пользователя место установки
!include MUI2.nsh
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES

; Добавить страницу завершения установки
!insertmacro MUI_PAGE_FINISH
