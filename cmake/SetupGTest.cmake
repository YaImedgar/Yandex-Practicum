if (TARGET libgtest)
    return()
endif()

include(DownloadUsingCPM)
CPMAddPackage(
        NAME googletest
        VERSION 1.11.0
        GIT_TAG release-1.11.0
        GITHUB_REPOSITORY google/googletest
        OPTIONS "INSTALL_GTEST OFF"
)

add_library(libgtest ALIAS gtest_main)  # Unify link names
add_library(libgmock ALIAS gmock)  # Unify link names