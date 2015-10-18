/*
Given n people and n+1 parking slots. Each person has a car and a parking slot allocated. One night they all go to a party and get drunk. They end up parking their cars randomly. What’s the best way to go back to the initial configuration (one where every car is in the right allocated slot). (N+1)th parking slot can be used to swap the cars.
*/

/*
Solution - 
Deriving the question - 
1.  Lets say the orginal order of each owner of parking cars is-
  org = [1,2,3,7,5]
  i.e. owner1 --> slot1 ; owner2 --> slot2 ; owner4-->slot7 etc.
2. After getting drunk, the order is -
  mod = [,3,1,2,7,5]
3. To rearange the order, we just need to sort the mod array according to order defined by org array.
  So - the question reduces to just sort one array according to order defined by another array.

4. Simple solition is just to write modified compare method - 
  //create map from org index
  for(int i=0;i<n;i++)
    map[ org[i] ] = i;
    
  int compare(int p1,int p2){ //current position of car1, car2
    int index1 = map[p1]; //get orginial index of car1 from Map that already prepared
    int index2 = map[p2];
    return (index1 < index2);
  }
  */
  
  /*If need to write entire sorting algorithm-
  I would select quick sort -
  */
  int partition(int mod[],int l,int r){
    int i = l-1;
    int p = map[ mod[r] ];  //index of last element
    for(int j=l;j<r;j++) {
      int p1= map[ mod[j] ];
      if(p1 < p) {
        i++;
        swap(mod[i],mod[j]);
      }
    }
    swap(mod[i+1],mod[r]);
    return (i+1);
  }
  void qsort(int mod[],int l,int r){
    if(l<r){
      int p = partition(mod,l,r);
      qsort(mod,l,p-1);
      qsort(mod,p+1,r);
    }
  }
