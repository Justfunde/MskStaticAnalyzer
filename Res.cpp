#include "Includes/LayoutReader_MSK.hpp"
#include "Includes/MskStaticAnalyzer.hpp"

constexpr uint32_t g_maxConsoleParamCnt = 5;
constexpr uint32_t g_CheckoutParam = 1;
constexpr uint32_t g_MskFileNameInd = 2;
constexpr uint32_t g_ruleFileNameInd = 3;
constexpr uint32_t g_outputFileName = 4;


std::vector<std::string>
SplitConsoleStrings(
   int argc,
   char* argv[])
{
  
   std::vector<std::string> strings;

   for (uint8_t i = 0; i < argc; i++)
   {
      strings.push_back(argv[i]);
   }
   return strings;
}


int main(int argc, char* argv[]) {
  
   try
   {
     if (1 == argc || g_maxConsoleParamCnt < argc) { throw std::runtime_error("Invalid number of parameters"); }

      auto consoleData = SplitConsoleStrings(argc, argv);

      if("--proc" != consoleData.at(g_CheckoutParam)) { throw std::runtime_error("Invalid console param"); }

      RuleParser ruleParser(consoleData.at(g_ruleFileNameInd));
      if (!ruleParser.ParseFile()) { throw std::runtime_error("Rule file was not parsed!"); }

      std::cout << "\nRule was parced well!\n";

      LayoutData layoutData;


      LayoutReader* layoutReader = GetReader(std::wstring(consoleData.at(g_MskFileNameInd).begin(), consoleData.at(g_MskFileNameInd).end()));
      if (!layoutReader) { throw std::runtime_error("Can't file appropriate reader for given file"); }
      if (!layoutReader->Read(&layoutData)) { throw std::runtime_error("Can't read file"); }
      FreeReader(layoutReader);

      std::cout << "File was read correct!\n";

      MskStaticAnalyzer analyzer;

      analyzer.SetParameters(&layoutData, ruleParser.GetRules());
      if (!analyzer.WriteAnalyzedFile(consoleData.at(g_outputFileName))) { throw std::runtime_error("Can't write analyzed file!");  }
      std::cout << "Output file is constructed!\n";

   }
   catch (const std::exception& ex)
   {
      std::cerr << "\nExteption:" << ex.what() << std::endl;
      return EXIT_FAILURE;
   }
   return 0;
}