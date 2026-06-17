# Niyebe Installer

This guide is about creating an installer for Niyebe using the Qt Installer Framework (QIF).

### Software Requirements
- Qt Installer Framework
- Niyebe `.zip` package that contains the executable file and its `.dll` dependencies

## Steps

1. Create `config/config.xml` with the following content:

    ```xml
    <?xml version="1.0" encoding="UTF-8"?>
    <Installer>
        <Name>Niyebe</Name>
        <Version>1.2.0</Version>
        <Title>Niyebe 1.2.0 Installer</Title>
        <Publisher>Jero Bado</Publisher>
        <StartMenuDir>Niyebe</StartMenuDir>
        <TargetDir>@ApplicationsDirX64@/Niyebe</TargetDir>
        <WizardStyle>Classic</WizardStyle>
    </Installer>
    ```

2. Copy your `.zip` package to `packages/com.vendor.product` directory

3. Run `binarycreator` tool from QIF to create the installer

    ```
    binarycreator --offline-only -c config/config.xml -p packages niyebe-installer.exe -v
    ```

    This will create the `niyebe-installer.exe`.

    Make sure `binarycreator` is in your path.

4. Run `niyebe-installer.exe` to test your installer.