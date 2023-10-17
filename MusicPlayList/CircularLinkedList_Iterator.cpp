#include "CircularLinkedList_Iterator.h"
#include "CircularLinkedList.h"
CircularLinkedList_Iterator::CircularLinkedList_Iterator(CircularLinkedList* input) : _circularLinkedList(input)
{
}

CircularLinkedList_Iterator::~CircularLinkedList_Iterator()
{
    delete _circularLinkedList;
}

Iterator* CircularLinkedList_Iterator::First()
{
    CircularLinkedList_Iterator* returnIter = new CircularLinkedList_Iterator(_circularLinkedList);
    returnIter->SetIndex(1);

    return returnIter;
}

Iterator* CircularLinkedList_Iterator::Last()
{
    CircularLinkedList_Iterator* returnIter = new CircularLinkedList_Iterator(_circularLinkedList);
    returnIter->SetIndex(_circularLinkedList->SizeOf());

    return returnIter;

}

Iterator* CircularLinkedList_Iterator::Next()
{
    CircularLinkedList_Iterator* returnIter = new CircularLinkedList_Iterator(_circularLinkedList);
    
    //SetIndex 전 인덱스/사이즈 체크
    _index += 1;
    if (_index > _circularLinkedList->SizeOf())
    {
        _index = 1;
    }
    returnIter->SetIndex(_index);
    return returnIter;
}

Iterator* CircularLinkedList_Iterator::Current()
{
    CircularLinkedList_Iterator* returnIter = new CircularLinkedList_Iterator(_circularLinkedList);
    returnIter->SetIndex(_index);

    return returnIter;
}

std::string CircularLinkedList_Iterator::CurrentData()
{
    std::string result = _circularLinkedList->At(_index);
    return result;
}

//마지막 요소인지 확인후 참/거짓 반환
//Iterator* CircularLinkedList_Iterator::Last()와 중복?
bool CircularLinkedList_Iterator::IsEnd()
{
    if (this->_index == _circularLinkedList->SizeOf())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//컨테이너의 몇 번째요소인지 설정
void CircularLinkedList_Iterator::SetIndex(int _input)
{
    
    if (_input >= _circularLinkedList->SizeOf() + 1)
    {
        _input = 1;
    }
    _index = _input;
}

int CircularLinkedList_Iterator::GetIndex() const
{
    return _index;
}
