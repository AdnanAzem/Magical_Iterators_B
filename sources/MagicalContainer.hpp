#include <iostream>
#include <vector>
using namespace std;

namespace ariel{

    class MagicalContainer{
        private:
            vector <int> elements;
            vector <int*> primeElements;
            

        public:
            MagicalContainer(); // Default constructor
            void addElement(int); // Adding element to the container
            size_t size() const; // Return the size of the container
            void removeElement(int); // Removing element from the container
            vector<int> getElements() const; // return the container
            vector<int*> getPrimeElements() const { return primeElements;}

            class Iterator{
                private:
                    MagicalContainer& container;
                    size_t currentIndex;

                public:

                    Iterator() = delete; 
                    Iterator(Iterator&&) = delete;
                    Iterator& operator=(Iterator&&) = delete;  
                    Iterator& operator=(const Iterator& other) = delete;  
                                     
                    Iterator(MagicalContainer& magicalContainer): container(magicalContainer), currentIndex(0){}
                    Iterator(MagicalContainer& magicalContainer, size_t index): container(magicalContainer), currentIndex(index){}
                    Iterator(const Iterator& other):container(other.container), currentIndex(other.currentIndex){}

                    void setContainer(MagicalContainer& cont){ container = cont;}
                    void setIndex(size_t num){ currentIndex = num;}
                    void increase(size_t num){ currentIndex += num;}
                    MagicalContainer& getContainer() const{return container;}
                    size_t getIndex() const{return currentIndex;}

                    virtual bool operator==(const Iterator& other) const{return &container == &other.container && currentIndex == other.currentIndex;}// Equality comparison  
                    virtual bool operator!=(const Iterator& other) const{return !(*this == other);}// Inequality comparison   
                    virtual bool operator>(const Iterator& other) const{return currentIndex > other.currentIndex;}// Greater than comparison  
                    virtual bool operator<(const Iterator& other) const{return currentIndex < other.currentIndex;}// Less than comparison  
                    virtual ~Iterator();

            };


        class AscendingIterator: public Iterator{

            public:
            AscendingIterator( MagicalContainer &, size_t);
            AscendingIterator( MagicalContainer& magicalContainer);
            AscendingIterator(const AscendingIterator& other);// Copy constructor      

            AscendingIterator() = delete; 
            AscendingIterator(AscendingIterator&&) = delete;
            AscendingIterator& operator=(AscendingIterator&&) = delete;

            ~AscendingIterator() override;// Destructor    
            AscendingIterator& operator=(const AscendingIterator& other);// Assignment operator   
            int operator*() const ;// Dereference operator   
            AscendingIterator& operator++(); // Pre-increment operator
            AscendingIterator begin()const;
            AscendingIterator end()const;
        };

        class SideCrossIterator : public Iterator{

            public:
                SideCrossIterator() = delete; 
                SideCrossIterator(SideCrossIterator&&) = delete;
                SideCrossIterator& operator=(SideCrossIterator&&) = delete;

                SideCrossIterator( MagicalContainer &, size_t);
                SideCrossIterator( MagicalContainer& magicalContainer) ;                
                SideCrossIterator(const SideCrossIterator& other) ;// Copy constructor       
                ~SideCrossIterator() override;// Destructor              
                SideCrossIterator& operator=(const SideCrossIterator& other);// Assignment operator                 
                int operator*() const ; // Dereference operator                
                SideCrossIterator& operator++() ; // Pre-increment operator
                SideCrossIterator begin()const;
                SideCrossIterator end()const;
        };

        class PrimeIterator : public Iterator{

            public:
                PrimeIterator() = delete; 
                PrimeIterator(PrimeIterator&&) = delete;
                PrimeIterator& operator=(PrimeIterator&&) = delete;

                PrimeIterator( MagicalContainer &, size_t);
                PrimeIterator( MagicalContainer& magicalContainer);
                PrimeIterator(const PrimeIterator& other);// Copy constructor
                ~PrimeIterator() override;// Destructor 
                PrimeIterator& operator=(const PrimeIterator& other);// Assignment operator
                int operator*() const ;// Dereference operator
                PrimeIterator& operator++() ;// Pre-increment operator
                PrimeIterator begin()const;
                PrimeIterator end()const;

        };
    };
}