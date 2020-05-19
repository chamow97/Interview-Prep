items = []
var StockSpanner = function() {
    items = []
};

/** 
 * @param {number} price
 * @return {number}
 */

StockSpanner.prototype.next = function(price) {
    let curr = 0;
    while(items.length > 0 && items[items.length - 1][0] <= price) {
        curr += (items[items.length - 1][1]);
        items.pop();
    }
    curr += 1;
    items.push([price, curr]);
    return curr;
};

/** 
 * Your StockSpanner object will be instantiated and called as such:
 * var obj = new StockSpanner()
 * var param_1 = obj.next(price)
 */
