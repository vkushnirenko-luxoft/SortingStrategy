#include "include/sorter.h"
#include "include/sortstrategyfactory.h"

Sorter::Sorter(std::unique_ptr<SortStrategyFactory> factory):
    factory_(std::move(factory)) {
    strategy_ = std::move(factory_->createSortStrategy(kMergeSort));
}

Sorter::~Sorter(){}

void Sorter::set(SortingType srt_type){
    strategy_ = std::move(factory_->createSortStrategy(srt_type));
}

void Sorter::sort(std::vector<std::string>& lines, CompareType cmp_type){
    strategy_->sort(lines, cmp_type);
}

