#include "LayoutReader_MSK.hpp"
#include "MskStaticAnalyzer.hpp"
#include <array>

constexpr uint32_t g_maxConsoleParamCnt = 4;
constexpr uint32_t g_MskFileNameInd = 1;
constexpr uint32_t g_ruleFileNameInd = 2;
constexpr uint32_t g_outputFileName = 3;


std::vector<std::string>
SplitConsoleStrings(
   int argc,
   char* argv[])
{
  
   std::vector<std::string> strings(argc);

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

      RuleParser ruleParser(consoleData.at(g_ruleFileNameInd));
      if (!ruleParser.ParseFile()) { throw std::runtime_error("Rule file was not parsed!"); }


      LayoutData layoutData;


      LayoutReader* layoutReader = GetReader(std::wstring(consoleData.at(g_MskFileNameInd).begin(), consoleData.at(g_MskFileNameInd).end()));
      if (!layoutReader) { throw std::runtime_error("Can't file appropriate reader for given file"); }
      if (!layoutReader->Read(&layoutData)) { throw std::runtime_error("Can't read file"); }
      FreeReader(layoutReader);

      MskStaticAnalyzer analyzer;

      analyzer.SetParameters(&layoutData, ruleParser.GetRules());
      if (!analyzer.WriteAnalyzedFile(consoleData.at(g_outputFileName))) { throw std::runtime_error("Can't write analyzed file!");  }
   }
   catch (const std::exception& ex)
   {
      std::cerr << "Exteption:" << ex.what() << std::endl;
      return EXIT_FAILURE;
   }
   return 0;
}