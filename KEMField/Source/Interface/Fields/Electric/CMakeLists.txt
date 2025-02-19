# CMakeLists for KEMField/Interface/Fields/Electric
# Author: W.Gosda

# header files
set( FIELDS_ELECTRIC_HEADER_BASENAMES
    KBoundaryElementInfoDisplay.hh
    KElectricField.hh
    KElectricQuadrupoleField.hh
    KElectrostaticConstantField.hh
    KElectrostaticLinearField.hh
        KElectrostaticExpoField.hh
        KElectrostaticImportField.hh
    KElectrostaticField.hh
    KElectrostaticBoundaryField.hh
    KElectrostaticBoundaryFieldTimer.hh
    KInducedAzimuthalElectricField.hh
    KRampedElectricField.hh
    KRampedElectric2Field.hh
)

set( FIELDS_ELECTRIC_HEADER_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

foreach( BASENAME ${FIELDS_ELECTRIC_HEADER_BASENAMES} )
    list( APPEND FIELDS_ELECTRIC_HEADER_FILENAMES ${FIELDS_ELECTRIC_HEADER_PATH}/${BASENAME} )
endforeach( BASENAME )

# source files
set( FIELDS_ELECTRIC_SOURCE_BASENAMES
    KBoundaryElementInfoDisplay.cc
    KElectricQuadrupoleField.cc
    KElectrostaticConstantField.cc
    KElectrostaticLinearField.cc
        KElectrostaticExpoField.cc
        KElectrostaticImportField.cc
    KElectrostaticBoundaryField.cc
    KElectrostaticBoundaryFieldTimer.cc
    KInducedAzimuthalElectricField.cc
    KRampedElectricField.cc
    KRampedElectric2Field.cc
)

set( FIELDS_ELECTRIC_SOURCE_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
foreach( BASENAME ${FIELDS_ELECTRIC_SOURCE_BASENAMES} )
    list( APPEND FIELDS_ELECTRIC_SOURCE_FILENAMES ${FIELDS_ELECTRIC_SOURCE_PATH}/${BASENAME} )
endforeach( BASENAME )

# library
add_library( KEMFieldsElectric SHARED
    ${FIELDS_ELECTRIC_SOURCE_FILENAMES} ${FIELDS_ELECTRIC_HEADER_FILENAMES} )
#set_target_properties( KEMFieldsElectric PROPERTIES COMPILE_FLAGS -Wno-overloaded-virtual )

target_include_directories(KEMFieldsElectric
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
target_link_libraries( KEMFieldsElectric
    PUBLIC
        KommonCore
        KEMMath
        KEMElectricFieldSolvers
        KEMFieldChargeDensitySolvers
        # KEMFieldElectricBoundaryIntegrators
        KEMFieldsMagnetic  # for induced fields
        KGeoBagCore
)

# install
kasper_install_headers( ${FIELDS_ELECTRIC_HEADER_FILENAMES} )
kasper_install_libraries( KEMFieldsElectric )
