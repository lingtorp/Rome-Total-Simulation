/* User interface help strings
 * - Contains user interface strings displayed in the UI
 */

// TODO: Handle language selection somehow
// en (English)
// sv (Swedish)
enum LANGUAGES { en, NUM_LANGUAGES };

// ----- HELP STRINGS -----
// Help strings are displayed in their own window as a detailed explanation
// coupled with a teaspoon of historical content to give the text its context.
// They are longer than description strings and are the full explanation of
// their relevant subject excluding providing gameplay information (stats, etc)

// TODO: Adopt these conventions in main.c
const char *aqueduct_help_str[NUM_LANGUAGES] = {
    "Provides water for public consumption and the baths."};

const char *basilica_help_str[NUM_LANGUAGES] = {""};

const char *farm_help_str[NUM_LANGUAGES] = {
    "Farms produces various types of foodstuffs."};

const char *senate_house_help_str[NUM_LANGUAGES] = {
    "Meeting place of the Senate. Enables Laws and increase political power."};

const char *temple_help_strs[NUM_LANGUAGES] = {"Increases various powers."};

const char *coin_mint_help_str[NUM_LANGUAGES] = {
    "Reduces the negative effects of war. Increases gold income. Provides "
    "coinage."};

const char *insula_help_str[NUM_LANGUAGES] = {
    "Multistory apartment building for the plebians."};

const char *forum_help_str[NUM_LANGUAGES] = {"Public square."};

const char *port_ostia_help_str[NUM_LANGUAGES] = {
    "Enables import and export of foodstuffs"};

const char *bakery_help_str[NUM_LANGUAGES] = {
    "Increase the amount of food produces by farms."};

const char *circus_maximus_help_str[NUM_LANGUAGES] = {""};

const char *villa_publica_help_str[NUM_LANGUAGES] = {""};

const char *bath_help_str[NUM_LANGUAGES] = {""};

const char *taberna_help_strs[NUM_LANGUAGES] = {""};

const char *taberna_bakery_help_strs[NUM_LANGUAGES] = {""};

// ----- DESCRIPTION STRINGS -----
// Description string are displayed where space is constrained and is a short
// explanatory text that may include gameplay information for the UI.

const char *aqueduct_description_strs[NUM_LANGUAGES] = {""};

const char *basilica_description_strs[NUM_LANGUAGES] = {"House of Law"};

const char *bath_description_strs[NUM_LANGUAGES] = {
    "Roman bath complexes was a crucial part of life in the city"};

const char *circus_maximus_description_strs[NUM_LANGUAGES] = {""};

const char *villa_publica_description_strs[NUM_LANGUAGES] = {""};

const char *farm_description_strs[NUM_LANGUAGES] = {
    "The Roman society was in large part an agricultural one. On many farms "
    "like this one sprinkled around the provinces the mouths of the mighty "
    "city Rome was feed."};

const char *forum_description_strs[NUM_LANGUAGES] = {
    "Perhaps the most famous of all the forums "};

const char *insula_description_strs[NUM_LANGUAGES] = {
    "Apartment block with space for 300 residents."};

const char *taberna_description_strs[NUM_LANGUAGES] = {""};

const char *temple_description_strs[NUM_LANGUAGES] = {
    "Used in festivals & sacrifies and other Roman traditions"};

const char *coin_mint_description_strs[NUM_LANGUAGES] = {""};

const char *senate_house_description_strs[NUM_LANGUAGES] = {""};

// ----- HISTORICAL TIDBITS STRINGS -----
// Historical strings give a short-ish historically relevant description
// regarding their subject

const char *aqueduct_tidbit_strs[NUM_LANGUAGES] = {""};

const char *coin_mint_tidbit_strs[NUM_LANGUAGES] = {
    "Starting from around 450 BC coins were minted in the Roman Republic. "
    "These replaced the previous bronze weights which had the effect of making "
    "trading easier for everyone."};

const char *insula_tidbit_strs[NUM_LANGUAGES] = {
    "In Rome these multistory apartment complexes was a common housing "
    "situation for the city's inhabitants."};
