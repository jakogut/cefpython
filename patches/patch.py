# CEF Python patches to Chromium and CEF.
# See upstream cef/patch/patch.cfg for how patching works in CEF.
# Current working directory is cef_build_dir/chromium/cef/ .
# See also docs/Build-instructions.md and tools/automate.py .

import platform

OS_POSTFIX = ("win" if platform.system() == "Windows" else
              "linux" if platform.system() == "Linux" else
              "mac" if platform.system() == "Darwin" else "unknown")

# LINUX
if OS_POSTFIX == "linux":
    # noinspection PyUnresolvedReferences
    patches.extend([
        # Chromium build issues
        {
            'name': '0002-chromium-compiler-r2',
            'path': '.'
        },
        #{
        #    'name': '0003-ffmpeg-r1',
        #    'path': '.'
        #},
        {
            'name': '0004-libwebp-shim-r0',
            'path': '.'
        },
        {
            'name': '0005-cors-string-r0',
            'path': '.'
        },
        {
            'name': '0006-libjpeg-r0',
            'path': '.'
        },
        {
            'name': 'vaapi',
            'path': '.'
        },
        {
            # Discovery of the "icudtl.dat" file fails on Linux.
            'name': 'issue231',
            'path': 'cef/'
        },
        {
            'name': 'implement-washidden-for-windowed-rendering',
            'path': 'cef/'
        },
        {
            'name': 'disable_Werror',
            'path': 'cef/',
        }
    ])
