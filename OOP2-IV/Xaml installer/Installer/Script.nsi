; ������ ������� ��������� �� NSIS � ������� ����� ���������

; ��������� ����� � ������ ���������
!define VERSION "1.0.0.0" ; ���������� ������ ������ ����������
!define COMPANY_NAME "IVT22 Nazar Stich"
!define PRODUCT_NAME "Time Calculator"
VIProductVersion ${VERSION}
VIAddVersionKey ProductName "${PRODUCT_NAME}"
VIAddVersionKey CompanyName "${COMPANY_NAME}"
VIAddVersionKey ProductVersion "${VERSION}"

Name "${PRODUCT_NAME}"
OutFile "Setup.exe"

; ����������� ������ ��� ���������
Section "����������"
    ; ��������� � ������������ ����� ���������
    SetOutPath "$INSTDIR"

    ; ����������� ������������ ����� � ������������ �����
    File "X:\Programming II\OOP2-IV\Xaml installer\TimeTimeTime\bin\Debug\TimeTimeTime.exe"

SectionEnd

; ���������� ���������
Section "������"
    MessageBox MB_OK "��������� ��������� �������!"
SectionEnd

; ��������� � ������������ ����� ���������
Function .onInit
    StrCpy $INSTDIR "C:\Program Files\${COMPANY_NAME}\${PRODUCT_NAME}"
FunctionEnd

; ��������� � ������������ ����� ���������
!include MUI2.nsh
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES

; �������� �������� ���������� ���������
!insertmacro MUI_PAGE_FINISH
